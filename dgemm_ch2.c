#include <stdio.h>
#include <stdlib.h>

void dgemm(int n, double* A, double* B, double* C)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double cij = C[i + j*n];    /* cij = C[i][j] */
            for( int k = 0; k < n; k++)
                cij += A[i+k*n] * B[k + j*n];
            C[i+j*n] = cij;
        }
    }
}

int main(int argc, char* argv[]) {
    int n = 960;
    double *A = malloc(sizeof(double) * n * n);
    double *B = malloc(sizeof(double) * n * n);
    double *C = malloc(sizeof(double) * n * n);

     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i + j*n] = 1.0;
            B[i + j*n] = 1.0;
            C[i + j*n] = 0.0;
        }
    }
    /* call the matrix multiplication function */
    dgemm(n, A, B, C);

    printf("%f\n", C[0]);
}