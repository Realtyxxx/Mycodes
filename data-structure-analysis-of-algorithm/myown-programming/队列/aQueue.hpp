#include "queueF.hpp"

#define defaultSize 15

template <typename E>
class AQueue : public Queue<E> {
 private:
  int maxSize;
  int front;
  int rear;
  E* listArray;

 public:
  AQueue(int size = defaultSize) {
    maxSize = size + 1;
    front = 1;
    rear = 0;
    listArray = new E[maxSize];
  }
  ~AQueue() { delete[] listArray; }

  void clear() {
    front = 1;
    rear = 0;
  }

  void enqueue(const E& it) {
    assert((rear + 2) % maxSize != front);
    rear = (rear + 1) % maxSize;
    listArray[rear] = it;
  }

  virtual int length() const {
    return ((rear + maxSize) - front + 1) % maxSize;
  }

  E dequeue() {
    assert(length() != 0);
    E it = listArray[front];
    front = (front + 1) % maxSize;
    return it;
  }

  const E& frontValue() const {
    assert(length() != 0);
    return listArray[front];
  }
};