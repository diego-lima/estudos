import time
import pythagorean_triples
 
 
def main():
    start = time.time()
    result = pythagorean_triples.count(1000)
    duration = time.time() - start
    print(result, duration)
 
 
if __name__ == '__main__':
    main()
