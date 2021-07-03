#include <cmath>
#include <iostream>
#include <set>
using namespace std;

void p(float k[][2], int size) {
  for (int i = 0; i < size; i++) {
    cout << "i_th: " << i << "  k[i][0] : " << k[i][0] << " k[i][1] : " << k[i][1] << endl;
  }
}

float *rank_array(float *array, int size) {
  float kv[size][2];
  float min = array[0], position, last;
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      if ((j = 0 || i != kv[j - 1][1]) && array[i] >= last && fabs(array[i] - last) >= 1e-6) {
        if (array[i] < min && fabs(array[i] - min) <= 1e-6) {
          min      = array[i];
          position = i;
        }
      }
    }
    kv[j][0] = min;
    kv[j][1] = position;
    last     = min;
  }
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
