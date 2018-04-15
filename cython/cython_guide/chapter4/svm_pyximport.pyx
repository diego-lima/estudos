"""
[1.2, 0.7] -> +1
[-0.3, 0.5] -> -1
[-3, -1] -> +1
[0.1, 1.0] -> -1
[3.0, 1.1] -> -1
[2.1, -3] -> +1
"""
from random import random
data = [
    [ 1.2, 0.7],
    [-0.3, 0.5],
    [  -3,  -1],
    [ 0.1, 1.0],
    [ 3.0, 1.1],
    [ 2.1,  -3]
]

labels = [
     1,
    -1,
     1,
    -1,
    -1,
     1
]

def pipeline():
    #
    # initial parameters
    #
    a = 1
    b = -2
    c = -1


    for iter in xrange(500000):
        # pick a random data point
        i = int(random() * len(data))
        x = data[i][0]
        y = data[i][1]
        label = labels[i]

        # compute pull
        score = a*x + b*y + c
        pull = 0.0
        if(label == 1 and score < 1):
            pull = 1
        if(label == -1 and score > -1):
            pull = -1

        # compute gradient and update parameters
        step_size = 0.01
        a += step_size * (x * pull - a) # -a is from the regularization
        b += step_size * (y * pull - b) # -b is from the regularization
        c += step_size * (1 * pull)
