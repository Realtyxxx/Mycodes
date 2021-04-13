#include <assert.h>

#include "Listf.h"

template <typename E>
class AList : public List<E> {
 private:
  int maxSize;
  int listSize;
  int curr;
  E* listArray;
  static const int defaultSize = 1001;

 public:
  E& operator[](int i) {
    assert(i >= 0 && i < listSize);
    return listArray[i];
  }

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
    assert(listSize < maxSize);
    for (int i = listSize; i > curr; i--) listArray[i] = listArray[i - 1];
    listArray[curr] = it;
    listSize++;
  }

  void append(const E& it) {
    assert(listSize < maxSize);
    listArray[listSize++] = it;
  }

  E remove() {
    assert((curr >= 0) && (curr < listSize));
    E it = listArray[curr];
    for (int i = curr; i < listSize - 1; i++) listArray[i] = listArray[i + 1];
    listSize--;
    return it;
  }

  void moveToStart() { curr = 0; }

  void moveToEnd() { curr = listSize--; }

  void prev() {
    if (curr != 0) curr--;
  }
  void next() {
    if (curr < listSize) curr++;
  }

  int currPos() { return curr; }
  int length() { return listSize; }

  void moveToPos(int pos) {
    assert((pos >= 0) && (pos <= listSize));
    curr = pos;
  }
  const E& getValue() const {
    assert((curr >= 0) && (curr <= listSize));
    return listArray[curr];
  }
};