
#define defaultSize 100


template <typename E>
class Stack {
 private:
  void operator=(const Stack&) {}
  Stack(const Stack&) {}

 public:
  Stack() {}
  virtual ~Stack() {}
  virtual void clear() = 0;
  virtual void push(const E&) = 0;
  virtual E pop() = 0;
  virtual const E& topValue() = 0;
  virtual int length() = 0;
};

//顺序表实现栈
template <typename E>
class AStack : public Stack<E> {
 private:
  int maxSize;
  E* listArray;
  int top;

 public:
  AStack(int size = defaultSize) {
    maxSize = size;
    top = 0;
    listArray = new E[size];
  }
  ~AStack() { delete[] listArray; }
  void clear() { top = 0; }
  void push(const E& it) {
    Assert(top != maxSize, "Stack is full");
    listArray[top++] = it;
  }
  E pop() {
    Assert(top != 0, "Stack is empty");
    return listArray[--top];
  }
  const E& topValue() const {
    Assert(top != 0, "Stack is empty");
    return listArray[top - 1];
  }
  int length() const { return top; }
};

