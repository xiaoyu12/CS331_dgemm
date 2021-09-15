# This is a sample Python script for matrix multiplication.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import numpy as np


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    n = 960
    #A = np.random.rand(n, n)
    #B = np.random.rand(n, n)
    #C = np.zeros((n, n))

    A = [[ 1.0 for i in range(n) ] for j in range(n) ]
    B = [[ 1.0 for i in range(n) ] for j in range(n) ]
    C = [[ 0.0 for i in range(n) ] for j in range(n) ]

    """for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    """
    C = np.matmul(A, B)

    print(C[0][0])

