#include <assert.h>
#include <sys/time.h>
#include <iostream>
#include <random>
#include <vector>

#include "heapSort.h"
#include "printVec.h"
#include "quickSort.h"
#include "radixSort.h"

// #define TESTTRUE 0
// #define TESTTIME 1
// #define array_length (1024 * 1024)
// #define array_length 10

using namespace std;

static struct timeval starttime;
static struct timeval endtime;

void tic(void) { gettimeofday(&starttime, NULL); }

double toc(void) {
  gettimeofday(&endtime, NULL);
  return (endtime.tv_sec - starttime.tv_sec) +
         1.0e-6 * (endtime.tv_usec - starttime.tv_usec);
}

void Assert(bool val, string s) {
  if (val) {
    cout << "断言失败：" << s << endl;
  }
}

int main(int argc, char** argv) {
  Assert(argc < 4,
         "Please use it as ./main $(vector_length) $(whether Test "
         "time) $(whether test correctness) $(sort kind)");
  int    array_length = atoi(argv[1]);
  int    TESTTIME     = atoi(argv[2]);
  int    TESTTRUE     = atoi(argv[3]);
  string sort_kind    = argv[4];
  srand(time(NULL));
  vector<int> myVec(array_length);
  for (int i = 0; i < myVec.size(); i++) {
    myVec[i] = rand() % 1024 + 1;
  }

  if (TESTTRUE) printVec(myVec);

  double elapsed;
  if (TESTTIME) tic();
  if (sort_kind == "radix") {
    radixSort(myVec);
  } else if (sort_kind == "quick") {
    quickSort(myVec);
  } else if (sort_kind == "heap") {
    heapSort(myVec);
  } else {
    cout << "Please give a sort_kind in \"quick\" or \"heap\" or \"radix\" "
         << endl;
  }
  if (TESTTIME) elapsed = toc();
  if (TESTTIME) cout << elapsed << endl;
  if (TESTTRUE) printVec(myVec);

  return 0;
}
