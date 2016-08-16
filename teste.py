import tensorflow as tf

x = tf.constant([[[2,3,1],[4,5,1],[1,2,1]],[[1,2,1],[4,5,1],[2,3,1]]])
slice1 = tf.slice(x,[0,0,0],[1,-1,-1])
slice2 = tf.slice(x,[1,0,0],[-1,-1,-1])

model = tf.initialize_all_variables()
with tf.Session() as sess:
    sess.run(model)
    # y = tf.concat(2, [slice1, slice2])
    print sess.run(slice2)
