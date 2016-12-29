import numpy as np
from time import time

N = 10000
x_len = 100000

def main():
    x = np.ones(x_len, dtype=np.float64) * 1.2345

    start = time()
    for i in xrange(N):
        y1 = np.cos(x, dtype=np.float64)
    end = time()
    print('cos: {} s'.format(end-start))

    start = time()
    for i in xrange(N):
        y2 = x * 7.9463
    end = time()
    print('multi: {} s'.format(end-start))

    start = time()
    for i in xrange(N):
        res = np.sum(x, dtype=np.float64)
    end = time()
    print('sum: {} s'.format(end-start))
    
    return y1, y2, res

if __name__ == '__main__':
    main()

# results
# cos: 22.7199969292 s
# multi: 0.841291189194 s
# sum: 1.15971088409 s
