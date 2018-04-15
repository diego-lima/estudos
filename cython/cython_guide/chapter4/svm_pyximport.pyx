"""
[1.2, 0.7] -> +1
[-0.3, 0.5] -> -1
[-3, -1] -> +1
[0.1, 1.0] -> -1
[3.0, 1.1] -> -1
[2.1, -3] -> +1
"""
# from random import random
from libc.stdlib cimport rand, RAND_MAX
data_points_list = [
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

cdef struct data_t:
    float x
    float y

cdef struct label_t:
    int z


cdef void make_dado_struct(list dados_list, data_t *dados_struct):
    cdef data_t *dado

    for i in range(len(dados_list)):
        dado = &dados_struct[i]
        dado[0].x = dados_list[i][0]
        dado[0].y = dados_list[i][1]

cdef data_t dados_struct[6]
make_dado_struct(data_points_list, dados_struct)

def pipeline():
    #
    # initial parameters
    #
    cdef:
        float a = 1, b = -2, c = -1, x, y
        float score, pull, step_size
        int i, label, length, iter, N = 500000

    length = len(data_points_list) - 1

    for iter in range(N):
        # pick a random data point
        i = int(rand()/(1.0*RAND_MAX)*length)
        x = dados_struct[i].x
        y = dados_struct[i].y
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