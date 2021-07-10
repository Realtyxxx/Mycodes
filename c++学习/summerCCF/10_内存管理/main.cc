#include <memory.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct usedMemory {
  int headidx;
  int tailidx;
  int size;
};

int   n, memorySize, allocCount = 0;
bool* memory;
// true means could be alloced

bool alloc(int);
bool erase(int);
void de_fragment();
void printMemory();

unordered_map<int, usedMemory> used;            // key: num of alloc number ;value: his information
unordered_map<int, int>        findAllocPoint;  // key:memory position ; value : alloc number

int main() {
  cin >> n >> memorySize;
  memory = new bool[memorySize];
  memset(memory, true, sizeof(bool) * memorySize);

  for (int i = 0; i < n; i++) {
    string cmd;
    int    x;
    // get command
    cin >> cmd;
    // deal with the command
    if (cmd == "alloc") {
      cin >> x;
      if (!alloc(x))
        // alloc x
        cout << "NULL" << endl;
      else
        cout << allocCount << endl;
    } else if (cmd == "erase") {
      // erase x
      cin >> x;
      if (!erase(x))
        cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
    } else if (cmd == "defragment") {
      // de_fragment
      de_fragment();
    } else {
      cout << "Input Error ,exit now" << endl;
      delete memory;
      return -1;
    }
  }
  delete memory;
  return 0;
}

bool alloc(int x) {
  int i, j;
  for (i = 0; i < memorySize; i++) {
    if (memory[i]) {
      j = 0;
      while (memory[j + i] && j < x)
        j++;
      if (--j == x - 1)
        break;
      else
        i += j;
    }
  }
  if (j < x - 1)
    return false;
  memset(&memory[i], false, sizeof(bool) * x);
  allocCount++;
  used[allocCount].headidx = i;
  used[allocCount].tailidx = i + j;
  used[allocCount].size    = x;
  findAllocPoint[i]        = allocCount;
  // printMemory();
  return true;
}

bool erase(int x) {
  if (used.count(x) == 0)
    return false;
  int h_idx = used[x].headidx;
  int t_idx = used[x].tailidx;

  findAllocPoint.erase(h_idx);
  while (h_idx <= t_idx) {
    memory[h_idx] = true;
    h_idx++;
  }
  used.erase(x);
  // printMemory();
  return true;
}

void de_fragment() {
  int free_begin = 0;  // where to put the re-alloced memory
  for (free_begin = 0; free_begin < memorySize; free_begin++) {
    if (!memory[free_begin]) {
      continue;
    } else {
      // printMemory();
      // find the place the memory was not used;
      int findD = free_begin;
      // then find the first need re-alloced memory;
      while (memory[findD] && findD < memorySize) {
        findD++;
      }
      if (findD == memorySize)
        return;
      // either hit the allocated place or the end of memory space ;
      if (!memory[findD]) {
        int num   = findAllocPoint[findD];  // get the owner number of this memory place ;
        int h_idx = findD;
        int len   = used[num].size;
        memset(&memory[h_idx], true, sizeof(bool) * len);        // free this place ;
        memset(&memory[free_begin], false, sizeof(bool) * len);  // take this place;
        used[num].headidx = free_begin;
        used[num].tailidx = free_begin + len - 1;
        free_begin += len - 1;
        // because it would have a self-incl right after then ,so not to skip a place;
      }
    }
  }
  // printMemory();
}

void printMemory() {
  for (int i = 0; i < memorySize; i++) {
    cout << memory[i] << " ";
  }
  cout << endl;
}