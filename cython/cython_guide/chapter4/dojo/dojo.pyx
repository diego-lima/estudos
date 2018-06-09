"""
[1.2, 0.7] -> +1
[-0.3, 0.5] -> -1
[-3, -1] -> +1
[0.1, 1.0] -> -1
[3.0, 1.1] -> -1
[2.1, -3] -> +1

SVM ---> Support Vector Machine
"""
from libc.stdlib cimport rand, RAND_MAX

data = [
    [ 1.2, 0.7],
    [-0.3, 0.5],
    [  -3,  -1],
    [ 0.1, 1.0],
    [ 3.0, 1.1],
    [ 2.1,  -3]
]

cdef struct data_t:
    float x
    float y

cdef void make_dado_struct(list dados_list, data_t *dados_struct):
    cdef data_t *dado

    for i in range(len(dados_list)):
        dado = &dados_struct[i]
        dado[0].x = dados_list[i][0]
        dado[0].y = dados_list[i][1]

def func():

# structs
labels = [
     1,
    -1,
     1,
    -1,
    -1,
     1
]


def pipeline():
    """
    y = a*x1 + b*x2 + c

    """
    "programa.c" > progoma.o
    "programa.pyx" > "programa.so"
    # a = 1

    """
    
    %timeit pythonpuro()
    %timeit cython_function()
    
    """
    cdef:
        float a,b,c
        int i, label, length
    cdef float a = 1
    cdef float b = -2
    cdef float c = -1
    cdef int i, label, length

    cdef float score, pull, step_size
    """profiling tools"""
    import time
    # import random
    s = time.time()

    length = len(data) - 1
    for iter in xrange(500000):
        # pick a random data point
        # i = int(random.random() * len(data))
        i = int( rand()/(1.0*RAND_MAX) *length)
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

    print time.time() - s

    return a,b,c



