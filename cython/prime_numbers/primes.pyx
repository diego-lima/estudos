import time

def primes (n):
    if n > 5000:
        n = 5000

    cdef int primes[5000]
    cdef int qtd = 0
    cdef int number = 2
    cdef int counter = 2

    while qtd < n:
        for i in range(2, number):
            if number % i == 0:
                counter = counter + 1
            if counter > 2:
                break
        if counter <= 2:
            primes[qtd] = number
            qtd = qtd + 1
        
        number = number + 1
        counter = 2
    
    return primes

if __name__ == '__main__':
    start = time.time()
    result = primes(20000)
    duration = time.time() - start
    print(len(result), duration)