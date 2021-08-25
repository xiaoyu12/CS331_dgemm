#include <stdio.h>
#include <stdlib.h>
#include <x86intrin.h>
#define UNROLL (4)

void dgemm(int n, double* A, double* B, double* C)
{
     for (int i = 0; i < n; i+=UNROLL*8)
        for (int j = 0; j < n; ++j){
           __m512d c[UNROLL];
           for (int r=0;r<UNROLL;r++)
             c[r] =  _mm512_load_pd(C+i+r*8+j*n); //[ UNROLL];

          for( int k = 0; k < n; k++ )
          {
             __m512d bb = _mm512_broadcastsd_pd(_mm_load_sd(B+j*n+k));
             for (int r=0;r<UNROLL;r++)
                c[r] = _mm512_fmadd_pd(_mm512_load_pd(A+n*k+r*8+i), bb, c[r]);
          }

          for (int r=0;r<UNROLL;r++)
             _mm512_store_pd(C+i+r*8+j*n, c[r]);
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
