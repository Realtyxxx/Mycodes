#include <cmath>
#include <iostream>
using namespace std;

void p(float k[][2], int size) {
  for (int i = 0; i < size; i++) {
    cout << "i_th: " << i << "  k[i][0] : " << k[i][0] << " k[i][1] : " << k[i][1] << endl;
  }
}

float *rank_array(float *array, int size) {
  float kv[size][2];  // kv[i][0] is the i_th value ,kv[i][1] is his position;
  float tmp, min = -1e25;
  int   position, i, j;
  //先排序，记录值
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (array[j] > min && fabs(array[j] - min) > 1e-6) {
        tmp = array[j];
        break;
      }
    }
    for (j = 0; j < size; j++) {
      if ((array[j] > min && fabs(array[j] - min) > 1e-6) &&
          (array[j] < tmp && fabs(tmp - array[j]) > 1e-6)) {
        tmp      = array[j];
        position = j;
      }
    }
    kv[i][0] = tmp;  //记录值的大小，i是排序后的大小
    kv[i][1] = j;    //记录值在原来数组的位置
    min      = tmp;
  }

  cout << "begin" << endl;
  p(kv, size);

  float rank = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 1; j + i < size && fabs(kv[i + j][0] - kv[i][0]) <= 1e-6; j++)
      ;
    j--;
    if (j != 0)
      rank = (i + j) / (j);
    for (int k = i; k <= i + j; k++) {
      array[(int)kv[k][1]] = rank;
    }
    i = j - 1;
  }
  return array;
}

int main() {
  float  array[5] = {3, 2, 6, 1, 3};
  float *rank     = rank_array(array, 5);
  for (int i = 0; i < 5; i++) {
    // std::cout << rank[i] << ", ";
  }
  std::cout << std::endl;
  // output: 2.5, 1, 4, 0, 2.5
}
