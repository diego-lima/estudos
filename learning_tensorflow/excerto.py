import tensorflow as tf

samples = [[3.,3.],[1.,1.]]
centroids = [[1.,2.],[4.,4.]]

expanded_vectors = tf.expand_dims(samples, 0)
expanded_centroids = tf.expand_dims(centroids, 1)
distances = tf.reduce_sum(tf.square(tf.sub(expanded_vectors, expanded_centroids)), 1)
with tf.Session() as sess:
    print 'Sub:'
    print sess.run(tf.sub(expanded_vectors,expanded_centroids))
    print 'Square:'
    print sess.run(tf.square(tf.sub(expanded_vectors, expanded_centroids)))
    print 'distances:'
    print sess.run(distances)
    square = sess.run(tf.square(tf.sub(expanded_vectors, expanded_centroids)))

for x in range(2):
    for y in range(2):
        for z in range(2):
            print 'Elemento [%d][%d][%d]' % (x,y,z)
            print square[x][y][z]
            print ''
