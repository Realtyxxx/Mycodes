#include <assert.h>

#include <iostream>

#include "Listf.h"

template <typename E>
class AList : public List<E> {
 private:
  int maxSize;
  int listSize;
  int curr;
  E* listArray;
  static const int defaultSize = 100;

 public:
  AList(int size = defaultSize) {
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize];
  }

  ~AList() { delete[] listArray; }

  void clear() {
    delete[] listArray;
    listSize = curr = 0;
    listArray = new E[maxSize];
  }

  void insert(const E& it) {
    Assert(listSize < maxSize);
    for (int i = listSize; i > curr; i--) listArray[i] = listArray[i - 1];
    listArray[curr] = it;
    listSize++;
  }

  void append(const E& it) {
    Assert(listSize < maxSize);
    listArray[listSize++] = it;
  }

  E remove() {
    Assert((curr >= 0) && (curr < listSize));
    E it = listArray[curr];
    for (int i = curr; i < listSize - 1; i++) listArray[i] = listArray[i + 1];
    listSize--;
    return it;
  }

  void moveToStart() { curr = 0; }

  void moveToEnd() { curr = listSize; }

  void prev() {
    if (curr != 0) curr--;
  }
  void next() {
    if (curr < listSize) curr++;
  }

  int length() const { return listSize; }
  int currPos() const { return curr; }

  void moveTOPos(int pos) {
    Assert((pos >= 0) && (pos <= listSize));
    curr = pos;
  }
  const E& getValue() const {
    Assert((curr >= 0) && (curr <= listSize));
    return listArray[curr];
  }
};