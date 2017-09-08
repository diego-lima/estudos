import tensorflow as tf
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import time

image = mpimg.imread('MarshOrchid.jpg')
h, w, d = image.shape
x = tf.Variable(image)
slice1 = tf.slice(x, [0,0,0], [h/2,-1,-1])
slice2 = tf.slice (x, [h/2,0,0], [-1,-1,-1])
model = tf.initialize_all_variables()

with tf.Session() as session:
    session.run(model)
    slice2 = tf.transpose(slice1, perm=[1, 0, 2])
    slice2 = tf.reverse_sequence(slice2, [2764] * w, 1, batch_dim=0)
    slice2 = tf.transpose(slice2, perm=[1, 0, 2])
    y = tf.concat(0, [slice1,slice2])
    result = session.run(y)

plt.imshow(result)
plt.show()
