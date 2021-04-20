#include "queue.h"

#define defaultSize 100

// Array-basedqueue implementation顺序队列的实现

template <typename E>
class AQueue : public Queue<E> {
 private:
  int maxSize;  // Maximum size of queue 队列最大容量

  int front;  // Index of front element 首元素位置

  int  rear;  // Index of rear element 尾元素位置

  E* listArray;  // Array holding queue elements 数组存放队列元素

 public:
  AQueue(int size = defaultSize) {  // Constructor 构造函数

    // Make list array one position larger forempty slot

    maxSize = size + 1;

    rear = 0;
    front = 1;

    listArray = new E[maxSize];
  }

  ~AQueue() { delete[] listArray; }  // Destructor 析构函数

  void  clear() {
    rear = 0;
    front = 1;
  }  // Reinitialize 重新初始化

  void enqueue(const E& it) {  // Put "it" in queue 入队

    Assert(((rear + 2) % maxSize) != front, "Queue is full");

    rear = (rear + 1) % maxSize;  // Circular increment 循环增加

    listArray[rear] = it;
  }

  E dequeue() {  // Take element out 删除队首元素

    Assert(length() != 0, "Queue is empty");

    E it = listArray[front];

    front = (front + 1) % maxSize;  // Circular increment 循环增加

    return it;
  }

  const E& frontValue() const {  // Get front value 取队首元素

    Assert(length() != 0, "Queue is empty");

    return listArray[front];
  }

  virtual int length() const  // Return length 返回队列长度

  {
    return ((rear + maxSize) - front + 1) % maxSize;
  }
};