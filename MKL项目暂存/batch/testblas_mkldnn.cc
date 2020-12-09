#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "mkl.h"
//#include <cblas.h>
//#include <fastblas.h> //包含CblasColMajor等定义
#include <sys/time.h>

using namespace std;

void test_uschgemm(int m, int n, int k, int loop) {
  unsigned char *A;
  signed char *B;
  int *C;
  int i, j, l;
  A = (unsigned char *)malloc(m * k * sizeof(unsigned char));
  B = (signed char *)malloc(k * n * sizeof(signed char));
  C = (int *)malloc(m * n * sizeof(int));
  const float alpha = 1;
  const float beta = 0;
  uint8_t ao = 0;
  int8_t bo = 0;
  int32_t co = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < k; j++) {
      //   A[i*k+j] = (i+1)%128;
      A[i * k + j] = rand() % 256;
      //   A[i*k+j] = (i+1)%128;
    }
  }
  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      B[i * n + j] = rand() % 256;
      //   B[i*n+j] = (j+1)%128;
    }
  }

  struct timeval start, end;
  gettimeofday(&start, 0);
  for (i = 0; i < loop; i++) {
    // fastblas_uschgemm(CblasRowMajor, CblasNoTrans, CblasTrans, m, n, k, 1, A,
    // k,
    //        B, k, 0, C, n);
    cblas_gemm_s8u8s32('N', 'T', 'F', m, n, k, alpha, A, k, ao, B, k, bo, beta,
                       C, n, &co);  // change here
  }
  gettimeofday(&end, 0);
  float time = ((double)(end.tv_sec - start.tv_sec) +
                (double)(end.tv_usec - start.tv_usec) / 1000000.);
  printf("cblas uschgemm time elapsed: %fs(%.4f GFlops)\n", time,
         loop * 1e-9 * m * n * k * 2 / time);

#if 1
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      int c_res = 0;
      for (l = 0; l < k; ++l) {
        c_res += A[i * k + l] * B[j * k + l];
      }
      if (c_res != C[i * n + j]) {
        printf(
            "cblas uschgemm error, res = %d, but get C = %d, i = %d, j = %d\n",
            c_res, C[i * n + j], i, j);
        //        exit(-1);
      }
    }
  }
  printf("calculation correct!\n");
#endif
  free(A);
  free(B);
  free(C);
  return;
}

int main() {
  int M[10] = {10, 30, 64, 100, 128, 256, 512, 800, 900, 1024};
  int N[10] = {10, 30, 64, 100, 128, 256, 512, 800, 900, 1024};
  int K[10] = {10, 30, 64, 100, 128, 256, 512, 800, 900, 1024};
  int i;

  printf("TEST USCHGEMM:\n");
  for (i = 0; i < 10; i++) {
    printf("M:%d N:%d K:%d		", M[i], N[i], K[i]);
    test_uschgemm(M[i], N[i], K[i], 1);
  }

  return 0;
}
