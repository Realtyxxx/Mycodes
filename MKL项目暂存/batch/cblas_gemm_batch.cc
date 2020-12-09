#include <stdio.h>
#include <iostream>
#include <vector>
#include "mkl.h"

int main(int argc, char **argv) {
  int raw_rows = 20;
  int raw_cols = 40;
  std::vector<float> a(raw_rows * raw_cols, 1.0);
  std::vector<float> b(raw_rows * raw_cols, 1.0);
  std::vector<float> c(1600, 0.0);

  // #define GRP_COUNT 1;
  MKL_INT GRP_COUNT;
  MKL_INT m_value;
  MKL_INT n_value;
  MKL_INT k_value;

  GRP_COUNT = atoi(argv[1]);  //命令行输入groupcount
  m_value = atoi(argv[2]);    //命令行输入统一的 m_value
  n_value = atoi(argv[3]);    //命令行输入统一的 n_value
  k_value = atoi(argv[4]);    //命令行输入统一的 k_value

  MKL_INT m[GRP_COUNT] = {20};
  MKL_INT k[GRP_COUNT] = {10};
  MKL_INT n[GRP_COUNT] = {20};

  MKL_INT lda[GRP_COUNT] = {40};
  MKL_INT ldb[GRP_COUNT] = {40};
  MKL_INT ldc[GRP_COUNT] = {80};

  CBLAS_TRANSPOSE transA[GRP_COUNT] = {CblasNoTrans};  // A
  CBLAS_TRANSPOSE transB[GRP_COUNT] = {CblasTrans};    // B转置

  float alpha[GRP_COUNT] = {1.0};  // C=alpha*A*Btrans+C*beta
  float beta[GRP_COUNT] = {1.0};

  const MKL_INT size_per_grp[GRP_COUNT] = {4};

  const float *a_array[4], *b_array[4];
  float *c_array[4];
  for (int i = 0; i < 4; ++i) {
    a_array[i] = a.data() + i * 10;
    b_array[i] = b.data() + i * 10;
    c_array[i] = c.data() + i * 20;
  }

  double s_initial, s_elapsed;  //时间

  s_initial = dsecnd();  // mkl.fi文件中的  second() / dsecnd()(double
                         // precision)   Elapsed realtime seconds

  cblas_sgemm_batch(CblasRowMajor, transA, transB, m, n, k, alpha, a_array, lda,
                    b_array, ldb, beta, c_array, ldc, GRP_COUNT, size_per_grp);

  s_elapsed = dsecnd() - s_initial;

  printf(
      " == Matrix multiplication using Intel(R) MKL cblas_sgemm_batch "
      "completed == \n"
      " == at %.5f milliseconds == \n\n",
      (s_elapsed * 1000));

  //输出矩阵A
  std::cout << "a.size(): " << a.size() << std::endl;
  for (int i = 0; i < a.size(); ++i) {
    std::cout << a[i] << " ";
    if ((i + 1) % 40 == 0) std::cout << std::endl;
  }

  std::cout << "b.size(): " << b.size() << std::endl;
  for (int i = 0; i < b.size(); ++i) {
    std::cout << b[i] << " ";
    if ((i + 1) % 40 == 0) std::cout << std::endl;
  }

  std::cout << "c_array.size(): " << 20 * 20 * 4 << std::endl;
  for (int i = 0; i < 1600; ++i) {
    std::cout << c[i] << " ";
    if ((i + 1) % 80 == 0) std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
