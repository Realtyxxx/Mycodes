#include <stdio.h>

#include <iostream>
#include <vector>

#include "mkl.h"

int main(int argc, char **argv) {
  MKL_INT Arg_G_Size = atoi(argv[1]);
  MKL_INT Arg_M_value = atoi(argv[2]);
  MKL_INT Arg_N_value = atoi(argv[3]);
  MKL_INT Arg_K_value = atoi(argv[4]);

  char arglayoutA = ARGV[5];
  char arglayoutB = ARGV[6];
  char arglayoutC = ARGV[7];

  int raw_cols = 40;
  std::vector<float> a(raw_rows * raw_cols, 1.0);
  std::vector<float> b(raw_rows * raw_cols, 1.0);
  std::vector<float> c(1600, 0.0);

  MKL_INT m = Arg_M_value;
  MKL_INT k = Arg_K_value;
  MKL_INT n = Arg_N_value;

  MKL_INT lda = ;
  MKL_INT ldb = 40;
  MKL_INT ldc = 80;

  CBLAS_TRANSPOSE transA = CblasNoTrans;  // A
  CBLAS_TRANSPOSE transB = CblasNoTrans;  // B转置

  float alpha = 1.0;  // C=alpha*A*Btrans+C*beta
  float beta = 1.0;

  // const MKL_INT size_per_grp = 4;

  int groupSize = atoi(argv[1]);

  const float *a_array[groupSize], *b_array[groupSize];
  float *c_array[groupSize];
  for (int i = 0; i < groupSize;
       ++i) {  //标记array[i]指向的数组开始的位置,现在只有一个group分为4个sub
    a_array[i] = a.data() + i * 40 / groupSize;  //指针操作
    b_array[i] = b.data() + i * 40 / groupSize;
    c_array[i] = c.data() + i * 80 / groupSize;
  }

  double s_initial, s_elapsed;  //时间

  s_initial = dsecnd();
  for (int i = 0; i < 4; i++) {
    cblas_sgemm(CblasRowMajor, transA, transB, m, n, k, alpha, a_array[i], lda,
                b_array[i], ldb, beta, c_array[i], ldc);
  }
  s_elapsed = dsecnd() - s_initial;

  printf(
      " == Multiple Matrix multiplication using Intel(R) MKL cblas_sgemm with "
      "for loop completed == \n"
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
