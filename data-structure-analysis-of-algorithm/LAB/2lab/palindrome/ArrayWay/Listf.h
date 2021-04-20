#ifndef _LISTF_
#define _LISTF_

template <typename E>
class List {
 private:
  void operator=(const List&) {}
  List(const List&) {}

 public:
  List() {}
  virtual void clear() = 0;
  virtual void insert(const E& item) = 0;
  virtual void append(const E& item) = 0;
  virtual E remove() = 0;
  virtual void moveToStart() = 0;
  virtual void moveToEnd() = 0;
  virtual void prev() = 0;
  virtual void next() = 0;
  virtual int currPos() = 0;
  virtual int length() = 0;
  virtual void moveToPos(int pos) = 0;
  virtual const E& getValue() const = 0;
  E& operator[](int) = 0;

};

#endif