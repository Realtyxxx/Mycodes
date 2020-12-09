//#include <iostream>
//#include <cstdio>
#include <cblas.h>

#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <pthread.h>

// using namespace std;
#define VERIFY_RESULTS
#define COMPARE

static struct timeval start;
static struct timeval end;

void tic(void) { gettimeofday(&start, NULL); }

double toc(void) {
  gettimeofday(&end, NULL);

  return (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
}

// colmajor
void printDiff(float *data1, float *data2, long width, long height,
               int iListLength, float fListTol) {
  printf("Listing first %d Differences > %.6f...\n", iListLength, fListTol);
  long i, j, k;
  int error_count = 0;

  for (i = 0; i < width; i++) {
    if (error_count < iListLength) {
      printf("\n  Col %d:\n", (int)i);
    }
    for (j = 0; j < height; j++) {
      k = i * height + j;
      float fDiff = fabs(data1[k] - data2[k]);

      if (fDiff > fListTol) {
        if (error_count < iListLength) {
          printf("    Loc(%d,%d)\tCPU=%.5f\tBLAS=%.5f\tDiff=%.6f\n", (int)j,
                 (int)i, data1[k], data2[k], fDiff);
        }

        error_count++;
      }
    }
  }

  printf(" \n  Total Errors = %d\n", error_count);
}

void printLWC(float *data1, float *data2, long width, long height,
              int iListLength, float fListTol) {
  // printf("Listing first %d Differences > %.6f...\n", iListLength, fListTol);
  long i, j, k;
  int error_count = 0;

  for (i = 0; i < width; i++) {
    // if (error_count < iListLength)
    //{
    //    printf("\n  Col %d:\n", (int)i);
    //}

    for (j = 0; j < height; j++) {
      k = i * height + j;

      //------------------------lwc----------------------------------------------------------//
      // printf("------------------------C----------------------------\n");
      printf("C:");
      printf("%f\t\t%f\n", data1[k], data2[k]);
      // printf("-----------------------------------------------------\n");
      //-------------------------------------------------------------------------------------//
      // float fDiff = fabs(data1[k] - data2[k]);

      // if (fDiff > fListTol)
      //{
      // if (error_count < iListLength)
      //{
      //    printf("    Loc(%d,%d)\tCPU=%.5f\tBLAS=%.5f\tDiff=%.6f\n", (int)j,
      //    (int)i, data1[k], data2[k], fDiff);
      //}
    }
  }

  // printf(" \n  Total Errors = %d\n", error_count);
}

// Allocates a matrix with random float entries. no ld, it is need fixed later.
void randomInit(float *data, long size) {
  long i;

#pragma omp parallel for
  for (i = 0; i < size; ++i) {
    data[i] = rand() / (float)RAND_MAX;
    // data[i] = i+1;
    //      printf("i=%d, ThreadID=%d\n",i,omp_get_thread_num());
    //  data[i] = (float)i+1;
  }
}

// multiply C=alpha*A*B
// multiply C=alpha*A*B+beta*C
// Colmajor
void matrixMulCPU(float *C, float *A, float *B, long hA, long wA, long wB,
                  float alp, float bet) {
  long i, j, k;
  float sum, a, b;

#pragma omp parallel for private(j, k, sum, a, b)
  for (j = 0; j < wB; ++j)
    for (i = 0; i < hA; ++i) {
      sum = 0;
      for (k = 0; k < wA; ++k) {
        a = A[i + k * hA];
        b = B[k + j * wA];
        sum += a * b;
      }

      C[i + j * hA] = sum * alp + bet * C[i + j * hA];
    }
}

int compareL2fe(float *cpuC, float *C, long size, float precision) {
  long i;

  // youtC[%d]:%s\n #pragma omp parallel for
  for (i = 0; i < size; i++) {
    if (fabs(cpuC[i] - C[i]) > precision) {
      return 0;
    }
  }
  return 1; /*the data is near to each other */
}

void MatrixCopy(float *C_direct, float *C_source, long size) {
  long i;
  for (i = 0; i < size; ++i) {
    C_direct[i] = C_source[i];
  }
}

void Transfer(float *C_dst, float *C_src, int ldc_dst, int ldc_src) {
  //-----------------------------------------------------lwc-------------------------------------------------------//
  // printf("------------------------------------------------lwc----------------------------------------------\n");

  // printf("Before Trans:\n");

  // for(int i=0;i<ldc_dst;i++)
  //{
  //        for(int j=0;j<ldc_src;j++)
  //        {
  //---------------------lwc------------------//
  //                printf("%f\n",C_src[i*ldc_src + j]);
  //        }
  //}
  /*
          //Transfer
          for(int i=0;i<ldc_dst;i++)
          {
              for(int j=0;j<ldc_src;j++)
              {
                  C_dst[j*ldc_dst+i] = C_src[i*ldc_src+j];
              }
          }
  */

  int i, j;
  for (j = 0; j < ldc_dst; j++) {
    for (i = 0; i < ldc_src; i++) {
      *(C_dst + j * ldc_src + i) = *(C_src + i * ldc_dst + j);
    }
  }

  // printf("After Trans:\n");

  // for(int i=0;i<ldc_src;i++)
  //{
  //        for(int j=0;j<ldc_dst;j++)
  //        {
  //---------------------lwc------------------//
  //                printf("%f\n",C_dst[i*ldc_dst + j]);
  //        }
  //}

  // printf("------------------------------------------------lwc----------------------------------------------\n");
  //---------------------------------------------------------------------------------------------------------------//
}

void printfMatrix(float *C, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%f ", C[i * n + j]);
    }
    printf("\n");
  }
}
/*
void MatrixTrans(float *Temp, float *Origin, int m, int n)
{
        // Origin matrix trans to Temp matrix
        // Row to Col, or Col to Row
    int i, j;
    float temp1[m][n];
    float temp_p;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            *(temp1[i] + j) = *(Origin + i*n + j);
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            temp_p = temp1[i][j];
            temp1[i][j] = temp1[j][i];
            temp1[j][i] = temp_p;
        }
    }
    
    
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            *(Temp + j*m + i) = *(temp1[i] + j);
        }
    }
    
}
*/
//-------------------------main-function--------------------------------------------

int main(int argc, char *ARGV[]) {
  int argcount = atoi(ARGV[1]);
  int argM = atoi(ARGV[2]);
  int argN = atoi(ARGV[3]);
  int argK = atoi(ARGV[4]);

  char arglayoutA = ARGV[5];
  char arglayoutB = ARGV[6];
  char arglayoutC = ARGV[7];

  int batch_count = argcount;

  enum CBLAS_ORDER layoutA[batch_count];
  enum CBLAS_ORDER layoutC[batch_count];
  for (int i = 0; i < batch_count; i++) {
    layoutA[i] = arglayoutA == 'C' ? CblasColMajor : CblasRowMajor;
    layoutC[i] = arglayoutC == 'R' ? CblasRowMajor : CblasColMajor;
  }
  enum CBLAS_ORDER layoutB = arglayoutB == 'C' ? CblasColMajor : CblasRowMajor;

  enum CBLAS_TRANSPOSE transa[batch_count];
  enum CBLAS_TRANSPOSE transb;

  for (int i = 0; i < batch_count; i++) {
    transa[i] = CblasNoTrans;
  }
  transb = CblasNoTrans;

  int *m = (int *)malloc((size_t)batch_count * sizeof(int));
  int n = argN;
  int k = argK;
  for (int i = 0; i < batch_count; i++) {
    m[i] = argM;
    // n[i] = argN;
    // k[i] = argK;
  }

  int *lda = (int *)malloc((size_t)batch_count * sizeof(int));
  // int *ldb = (int*)malloc((size_t)batch_count*sizeof(int));
  int ldb = layoutC[0] == CblasColMajor ? k : n;
  // int ldb    = layoutC[0] == CblasColMajor ? n : k;
  int *ldc = (int *)malloc((size_t)batch_count * sizeof(int));
  // int ldb = n;
  for (int i = 0; i < batch_count; i++) {
    lda[i] = layoutC[i] == CblasColMajor ? m[i] : k;
    ldc[i] = layoutC[i] == CblasColMajor ? m[i] : n;
    // lda[i] = layoutC[i] == CblasColMajor ? k : m[i];
    // ldc[i] = layoutC[i] == CblasColMajor ? n : m[i];
  }

  float alpha[batch_count];
  float beta[batch_count];
  for (int i = 0; i < batch_count; i++) {
    alpha[i] = 1.0;
    beta[i] = 0.0;
  }

  float **A = (float **)malloc((size_t)batch_count * sizeof(float *));
  assert(A != NULL);

  float *B = (float *)malloc((size_t)k * n * sizeof(float));
  assert(B != NULL);

  float **C = (float **)malloc((size_t)batch_count * sizeof(float *));
  assert(C != NULL);

  //分配数据
  randomInit(B, k * n);
  for (int i = 0; i < batch_count; i++) {
    A[i] = (float *)malloc((size_t)k * m[i] * sizeof(float));
    assert(A[i] != NULL);

    // B[i] = (float*)malloc((size_t)ldb[i]*n[i]*sizeof(float));
    // assert(B[i] != NULL);

    C[i] = (float *)malloc((size_t)n * m[i] * sizeof(float));
    assert(C[i] != NULL);

    randomInit(A[i], m[i] * k);
    // randomInit (B[i], k[i] * n[i]);
    // randomInit (C[i], m[i] * n[i]);
    for (int p = 0; p < ldc[i] * n; p++) {
      C[i][p] = (float)0.0;  // temp since beta is deleted 20200701
    }
  }

#if defined VERIFY_RESULTS || defined COMPARE
  float **cpuC = (float **)malloc((size_t)batch_count * sizeof(float *));
  assert(cpuC != NULL);
  for (int i = 0; i < batch_count; i++) {
    cpuC[i] = (float *)malloc((size_t)n * m[i] * sizeof(float));
    assert(cpuC[i] != NULL);

    MatrixCopy(cpuC[i], C[i], m[i] * n);
  }
#endif
  // printf("A:\n(row)"); //row
  // printfMatrix(A[0],k,m[0]);
  // printf("B:\n(col)"); //row
  // printfMatrix(B,n,k);
  // struct timeval start,finish;
  // gettimeofday(&start,0);
  float **tmpA = (float **)malloc((size_t)batch_count * sizeof(float *));
  float *tmpB = (float *)malloc(n * k * sizeof(float));
  float **tmpC = (float **)malloc((size_t)batch_count * sizeof(float *));
  /*
          float elapsed_time=0.0;
          tic();
          cblas_sgemm_batch(batch_count,
                                          layoutA,layoutB,layoutC,
                                          (const CBLAS_TRANSPOSE *)transa,(const
     CBLAS_TRANSPOSE )transb, (const int *)m,(const int )n,(const int )k, (const
     float *)alpha, (float const *const *)A,(const int *)lda, (float const const
     *)B,(const int )ldb, (const float *)beta, C,(const int *)ldc
          );
          elapsed_time = toc();
  */

#ifdef VERIFY_RESULTS
  printf("Verifying on CPU ... \n");
  tmpB = (float *)malloc(n * k * sizeof(float));

  // printf("--------------------------TransB---------------------------\n");
  Transfer(tmpB, B, k, n);
  // printf("tmpB:\n(row)");
  // printfMatrix(tmpB,n,k);

  //      for(int i=0;i<batch_count;i++)
  //      {
  //          cblas_sgemm(CblasRowMajor,CblasNoTrans, CblasNoTrans,
  //                                m[i], n, k, alpha[i], A[i], lda[i],
  //                                B, ldb, beta[i], cpuC[i], ldc[i]);
  //      }

  for (int i = 0; i < batch_count; i++) {
    //    matrixMulCPU (cpuC[i], A[i], B[0], m[i], k[i], n[i],
    //    alpha[i],beta[i]);

    //转A
    tmpA[i] = (float *)malloc(m[i] * k * sizeof(float));
    // printf("-----------------------------TransA---------------------------\n");
    Transfer(tmpA[i], A[i], k, m[i]);
  }

  /*
        for(int i=0;i<batch_count;i++)
        {

                          //printf("tmpA:\n(row)");
                          //printfMatrix(tmpA[i],k,m[i]);
                          //直接在这
                          
                          if(layoutC[i] == CblasRowMajor){
                                  cblas_sgemm(CblasRowMajor,CblasNoTrans,
     CblasNoTrans, m[i], n, k, alpha[i], layoutA[i] == CblasColMajor ? tmpA[i] :
     A[i], lda[i], layoutB == CblasColMajor ? tmpB : B, n, beta[i], cpuC[i],
     ldc[i]); }else{ cblas_sgemm(CblasColMajor,CblasNoTrans, CblasNoTrans, m[i],
     n, k, alpha[i], layoutA[i] == CblasColMajor ? A[i] : tmpA[i], lda[i],
                                  layoutB == CblasColMajor ? B : tmpB, k,
     beta[i], cpuC[i], ldc[i]);
                          }
        }
  */

  float elapsed_time = 0.0;
  tic();
  cblas_sgemm_batch(batch_count, layoutA, layoutB, layoutC,
                    (const CBLAS_TRANSPOSE *)transa,
                    (const CBLAS_TRANSPOSE)transb, (const int *)m, (const int)n,
                    (const int)k, (const float *)alpha, (float const *const *)A,
                    (const int *)lda, (float const const *)B, (const int)ldb,
                    (const float *)beta, C, (const int *)ldc);
  elapsed_time = toc();

  double perf_total = 2.2 * 2 * 4;
  double dgemm_gflop = (2.0 * ((double)n) * ((double)m[0]) * ((double)k) *
                        ((double)batch_count) * 1e-9);
  printf("cblas_batchgemm time elapsed: %lf s\n", elapsed_time);
  printf(
      "count=%5ld, M=%5ld, N=%5ld, K=%5ld, time=%7.3f(s), gflop=%7.3f, "
      "Performance=%7.3f Gflops, Efficiency=%7.3f\%\n",
      batch_count, m[0], n, k, elapsed_time, dgemm_gflop,
      dgemm_gflop / elapsed_time,
      (dgemm_gflop / elapsed_time) / perf_total * 100.0);

  tic();
  for (int i = 0; i < batch_count; i++) {
    /*
                 for(int i=0;i<batch_count;i++)
                 {
                    cblas_sgemm(CblasRowMajor,CblasNoTrans, CblasNoTrans,
                                    m[i], n, k, alpha[i], A[i], lda[i],
                                    B, ldb, beta[i], cpuC[i], ldc[i]);
                 }
    */

    if (layoutC[i] == CblasRowMajor) {
      cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m[i], n, k,
                  alpha[i], layoutA[i] == CblasColMajor ? tmpA[i] : A[i],
                  lda[i], layoutB == CblasColMajor ? tmpB : B, n, beta[i],
                  cpuC[i], ldc[i]);
    } else {
      cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m[i], n, k,
                  alpha[i], layoutA[i] == CblasColMajor ? A[i] : tmpA[i],
                  lda[i], layoutB == CblasColMajor ? B : tmpB, k, beta[i],
                  cpuC[i], ldc[i]);
    }
  }
  elapsed_time = toc();
  printf("cblas_sgemm with loops time elapsed: %lf s\n", elapsed_time);
  printf(
      "count=%5ld, M=%5ld, N=%5ld, K=%5ld, time=%7.3f(s), gflop=%7.3f, "
      "Performance=%7.3f Gflops, Efficiency=%7.3f\%\n",
      batch_count, m[0], n, k, elapsed_time, dgemm_gflop,
      dgemm_gflop / elapsed_time,
      (dgemm_gflop / elapsed_time) / perf_total * 100.0);

  for (int i = 0; i < batch_count; i++) {
    // printf("C[%d]row\n",i);
    // printfMatrix(C[i],n,m[i]);
    tmpC[i] = (float *)malloc((size_t)n * m[i] * sizeof(float));
    // Transfer(tmpC[i],C[i],n,m[i]);
    // printf("tmpC[%d]col\n",i);
    // printfMatrix(tmpC[i],m[i],n);

    // printf("cpuC[%d]\n",i);
    // printfMatrix(cpuC[i],n,m[i]);
    /*verify. */

    if (!compareL2fe(cpuC[i], C[i], m[i] * n, 1.0e-6f)) {
      printf(
          "the generic result & the result using OpenBLAS or MKL is not near "
          "to each other\n");
      printf("the batch number is %d\n", i);
      printDiff(cpuC[i], C[i], ldc[i], n, 100, 1.0e-5f);
      printf("Results checking FAILED\n");
      // return 0;
    }
  }
  printf("Results checking PASSED\n");
#endif

  /*
        for(int i=0;i<batch_count;i++)
        {
            //printLWC(cpuC[i], C[i], ldc[i], n, 100, 1.0e-5f);
            printLWC(cpuC[i], C[i], n, ldc[i], 100, 1.0e-5f);
        }
  */

  // free array
  for (int matrix_iter = 0; matrix_iter < batch_count; matrix_iter++) {
    free(A[matrix_iter]);
    free(tmpA[matrix_iter]);
    // free(B[matrix_iter]);
    free(C[matrix_iter]);
    free(tmpC[matrix_iter]);
  }
  free(A);
  free(B);
  free(C);
  free(tmpA);
  free(tmpC);
  // free(n);
  free(m);
  // free(k);

  free(lda);
  // free(ldb);
  free(ldc);

#ifdef VERIFY_RESULTS
  for (int i = 0; i < batch_count; i++) {
    free(cpuC[i]);
  }
  free(cpuC);  // the baby is free before dad
#endif

  return 0;
}
