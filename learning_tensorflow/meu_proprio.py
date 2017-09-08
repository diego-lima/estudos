# -*- coding:utf-8 -*-
from my_functions import *
from math import log

def centroids_number(samples_number):
    n_centroids = 1 + (3.3 * log(samples_number, 60))
    print n_centroids
    return int(n_centroids)

def iterations_number(samples_number):
    n_centroids = 1 + (3.3 * log(samples_number, 10))
    print 'iterações:',n_centroids
    return int(n_centroids)

SAMPLE = create_samples(320,2)

CENTROIDS = choose_random_centroids(SAMPLE, centroids_number(len(SAMPLE)))
plot_initial_centroids(CENTROIDS)

for x in range(iterations_number(len(SAMPLE))):
    nearest_indices = assign_to_nearest(SAMPLE, CENTROIDS)
    CENTROIDS = update_centroids(SAMPLE,nearest_indices,len(CENTROIDS))

    plot_sample(SAMPLE)
    plot_centroids(CENTROIDS)

    plt.show()
