import time
import pyximport; pyximport.install()
import primes

if __name__ == '__main__':
    start = time.time()
    result = primes.primes(5000)
    duration = time.time() - start
    print(len(result), duration)