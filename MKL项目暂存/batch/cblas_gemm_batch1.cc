#include <iostream>
#include <vector>
#include <stdio.h>
#include "mkl.h"

int main()
{
  int raw_rows = 20;
  int raw_cols = 40;
  std::vector<float> a(raw_rows * raw_cols, 1.0);
  std::vector<float> b(raw_rows * raw_cols, 1.0);
  std::vector<float> c(400, 0.0);

#define GRP_COUNT 1
  MKL_INT m[GRP_COUNT] = {5};
  MKL_INT k[GRP_COUNT] = {10};
  MKL_INT n[GRP_COUNT] = {5};

  MKL_INT lda[GRP_COUNT] = {40};
  MKL_INT ldb[GRP_COUNT] = {40};
  MKL_INT ldc[GRP_COUNT] = {20};

  CBLAS_TRANSPOSE transA[GRP_COUNT] = {CblasNoTrans};
  CBLAS_TRANSPOSE transB[GRP_COUNT] = {CblasTrans};

  float alpha[GRP_COUNT] = {1.0};
  float beta[GRP_COUNT] = {0.0};

  const MKL_INT size_per_grp[GRP_COUNT] = {16};

  const float *a_array[16], *b_array[16];
  float *c_array[16];
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      a_array[i * 4 + j] = a.data() + i * 5 * 40 + j * 10;
      b_array[i * 4 + j] = b.data() + i * 5 * 40 + j * 10;
      c_array[i * 4 + j] = c.data() + i * 5 * 20 + j * 5;
    }
  }

  cblas_sgemm_batch(CblasRowMajor, transA, transB,
                    m, n, k, alpha,
                    a_array, lda,
                    b_array, ldb, beta,
                    c_array, ldc,
                    GRP_COUNT, size_per_grp);

  std::cout << "a.size(): " << a.size() << std::endl;
  for (int i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << " ";
    if ((i + 1) % 40 == 0)
      std::cout << std::endl;
  }

  std::cout << "b.size(): " << b.size() << std::endl;
  for (int i = 0; i < b.size(); ++i)
  {
    std::cout << b[i] << " ";
    if ((i + 1) % 40 == 0)
      std::cout << std::endl;
  }

  std::cout << "c_array.size(): " << 5 * 5 * 16 << std::endl;
  for (int i = 0; i < 400; ++i)
  {
    std::cout << c[i] << " ";
    if ((i + 1) % 20 == 0)
      std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
