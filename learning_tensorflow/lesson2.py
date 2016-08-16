 # -*- coding:utf-8 -*-
import tensorflow as tf
import numpy as np

# questão 2
data = np.random.randint(1000, size=10)
x = tf.constant(data)
y = tf.Variable(5*x*x - 3*x + 15, name='y')
# questão 3
x = tf.Variable(0, name='x')
model = tf.initialize_all_variables()
with tf.Session() as session:
    for i in range(5):
        session.run(model)
        x = x + 1
        # print(session.run(x))

# questão 4
x = tf.Variable(0)
model = tf.initialize_all_variables()
with tf.Session() as session:
    session.run(model)
    for i in range(5):
        x = x + np.random.randint(1000)
        # print 'x é ', session.run(x)
        # print 'media até aqui é', session.run(x)/(i + 1)

# questão 5
x = tf.constant(35, name='x')
print(x)
y = tf.Variable(x + 5, name='y')

with tf.Session() as session:
    merged = tf.merge_all_summaries()
    writer = tf.train.SummaryWriter("/tmp/basic", session.graph_def)
    model = tf.initialize_all_variables()
    session.run(model)
    print(session.run(y))
