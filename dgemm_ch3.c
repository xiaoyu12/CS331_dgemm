#include <stdio.h>
#include <stdlib.h>
#include <x86intrin.h>

void dgemm(int n, double* A, double* B, double* C)
{
    for (int i = 0; i < n; i+=8)
        for (int j = 0; j < n; ++j)
         {
           __m512d c0 = _mm512_load_pd(C+i+j*n);   // c0 = C[i][j]
           for (int k = 0; k < n; k++)
           {  // c0 += A[i][k]*B[k][j]
              __m512d bb = _mm512_broadcastsd_pd(_mm_load_sd(B+j*n+k));
             c0 = _mm512_fmadd_pd(_mm512_load_pd(A+n*k+i), bb, c0);
          }
          _mm512_store_pd(C+i+j*n, c0);  // C[i][j] = c0
       }
}

int main(int argc, char* argv[]) {
    int n = 960;
    double *A = aligned_alloc(64, sizeof(double) * n * n);
    double *B = aligned_alloc(64, sizeof(double) * n * n);
    double *C = aligned_alloc(64, sizeof(double) * n * n);

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
