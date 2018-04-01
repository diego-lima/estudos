import time


def count(limit):
    cdef int result = 0
    cdef int a = 0
    cdef int b = 0
    cdef int c = 0
 
    for a in range(1, limit + 1):
        for b in range(a + 1, limit + 1):
            for c in range(b + 1, limit + 1):
                if c * c > a * a + b * b:
                    break
 
                if c * c == (a * a + b * b):
                    result += 1
    return result 

 
if __name__ == '__main__':
    start = time.time()
    result = count(1000)
    duration = time.time() - start
    print(result, duration)
