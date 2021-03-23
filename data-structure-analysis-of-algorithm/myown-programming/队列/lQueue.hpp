#include <stddef.h>

#include "queueF.hpp"

#define defaultSize 15
template <typename E>
class Link {
 public:
  E element;
  Link* next;
  Link(const E& elemval, Link* nextval = NULL) {
    element = elemval, next = nextval;
  }
  Link(Link* nextval = NULL) { next = nextval; }
};

template <typename E>
class LQueue : public Queue<E> {
 private:
  Link<E>* front;
  Link<E>* rear;
  int size;

 public:
  LQueue(int size = defaultSize) {
    front = rear = new Link<E>;
    size = 0;
  }

  ~LQueue() {
    clear();
    delete front;
  }

  virtual void clear() {
    while (front->next != NULL) {
      rear = front;
      front = front->next;
      delete rear;
    }
    rear = front;
    size = 0;
  }

  virtual void enqueue(const E& it) {
    rear = rear->next = new Link<E>(it, NULL);
    size++;
  }

  virtual E dequeue() {
    assert(size != 0);
    E it = front->next->element;
    Link<E>* ltemp = front->next;
    front->next = front->next->next;
    if (rear == ltemp) rear = front;
    delete ltemp;
    size--;
    return it;
  }

  virtual const E& frontValue() {
    assert(size != 0);
    return front->next->element;
  }
  virtual int length() const { return size; }
  const E& frontValue() const {
    assert(size != 0);
    return front->next->element;
  }
};