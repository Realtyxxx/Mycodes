#include <assert.h>

#include <cstddef>
#include <iostream>

#include "Listf.h"

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
class Llist : public List<E> {
 private:
  Link<E>* head;
  Link<E>* curr;
  Link<E>* tail;
  int cnt;
  static const int defaultSize = 100;

  void init() { curr = tail = head = new Link<E>; }

  void removeall() {
    while (head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

 public:
  Llist(int size = defaultSize) { init(); }

  ~Llist() { removeall(); }

  void print() const {
    curr = head->next;
    while (curr) {
      std::cout << curr->element << " ";
      curr = curr->next;
    }
    std::cout << std::endl;
  }

  void clear() {
    removeall();
    init();
  }

  void insert(const E& it) {
    curr->next = new Link<E>(it, curr->next);
    if (tail == curr) tail = curr->next;
    cnt++;
  }

  void append(const E& it) {
    tail = tail->next = new Link<E>(it, NULL);
    cnt++;
  }

  E remove() {
    assert(curr->next != NULL);
    E it = curr->next->element;
    Link<E>* ltemp = curr->next;
    if (tail == curr->next) tail = curr;
    curr->next = curr->next->next;
    delete ltemp;
    cnt--;
    return it;
  }

  void moveToStart() { curr = head; }

  void moveToEnd() { curr = tail; }

  void prev() {
    if (curr == head) return;
    Link<E>* ltemp = head;
    while (ltemp->next != curr) ltemp = ltemp->next;
    curr = ltemp;
  }

  void next() {
    if (curr != tail) curr = curr->next;
  }

  int currPos() {
    Link<E>* ltemp = head;
    int i = 0;
    while (ltemp != curr) {
      ltemp = ltemp->next;
      i++;
    }
    return i;
  }

  int length() { return cnt; }

  void moveToPos(int pos) {
    assert(pos >= 0 && pos <= cnt);
    curr = head;
    while (pos--) curr = curr->next;
  }

  const E& getValue() const {
    assert(curr->next != 0);
    return curr->next->element;
  }
};
