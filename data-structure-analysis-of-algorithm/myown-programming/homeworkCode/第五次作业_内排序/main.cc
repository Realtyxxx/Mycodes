#include <sys/time.h>

#include <iostream>
#include <random>
#include <vector>

#include "heapSort.h"
#include "printVec.h"
#include "quickSort.h"

#define array_length (1024 * 1024)

using namespace std;

static struct timeval starttime;
static struct timeval endtime;

void tic(void) { gettimeofday(&starttime, NULL); }

double toc(void) {
  gettimeofday(&endtime, NULL);
  return (endtime.tv_sec - starttime.tv_sec) +
         1.0e-6 * (endtime.tv_usec - starttime.tv_usec);
}

int main() {
  srand(time(NULL));
  vector<int> myVec(array_length);
  for (int i = 0; i < myVec.size(); i++) {
    myVec[i] = rand() % 10000 + 1;
  }
  // printVec(myVec);
  double elapsed;
  tic();

  quickSort(myVec);
  // heapSort(myVec);
  elapsed = toc();
  cout << elapsed << endl;

  // printVec(myVec);

  return 0;
}