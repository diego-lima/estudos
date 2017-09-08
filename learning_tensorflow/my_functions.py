import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from numpy.linalg import norm as size

def plot_sample(sample):
    for amostra in sample:
        plt.scatter(amostra[0],amostra[1])

def plot_centroids(centroids):
    for centroid in centroids:
        plt.plot(centroid[0], centroid[1], markersize=15, marker="x", color='m', mew=3)

def plot_initial_centroids(centroids):
    for centroid in centroids:
        plt.plot(centroid[0], centroid[1], markersize=15, marker="o", color='k', mew=3)

def assign_to_nearest(sample, centroids):
    nearest_indices = []

    for index, data_point in enumerate(sample):
        data_point_distances = []
        for i, centroid in enumerate(centroids):
            distancia = size(data_point - centroid)
            data_point_distances.append(distancia)
        nearest_index = data_point_distances.index(np.amin(data_point_distances))
        nearest_indices.append(nearest_index)

    return nearest_indices

def update_centroids(samples, nearest_indices, n_clusters):
    updated_centroids = []
    with tf.Session() as sess:
        partitions = sess.run(tf.dynamic_partition(samples,nearest_indices,n_clusters))
        for partition in partitions:
            updated_centroids.append(sess.run(tf.reduce_sum(tf.to_float(partition),0)/len(partition)))
        return updated_centroids

def choose_random_centroids(samples, n_clusters):
    with tf.Session() as sess:
        n_samples = tf.shape(samples)[0]
        random_indices = tf.random_shuffle(tf.range(0, n_samples))
        begin = [0,]
        size = [n_clusters,]
        size[0] = n_clusters
        centroid_indices = tf.slice(random_indices, begin, size)
        initial_centroids = sess.run(tf.gather(samples, centroid_indices))
        return initial_centroids

def create_samples(n_samples, n_features, seed=None):
    np.random.seed(seed)
    with tf.Session() as sess:
        samples = sess.run(tf.random_normal((n_samples, n_features),
                               mean=4.0, stddev=2.0, dtype=tf.float64, seed=seed))
    return samples
