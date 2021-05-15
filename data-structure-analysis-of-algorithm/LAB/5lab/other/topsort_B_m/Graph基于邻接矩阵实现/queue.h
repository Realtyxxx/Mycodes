template <typename E>
class Queue {
 private:
  void operator=(const Queue&) {}  // Protect assignment

  Queue(const Queue&) {}  // Protect copy constructor

 public:
  Queue() {}  // Default 构造函数

  virtual ~Queue() {}  // Basedestructor 析构函数

  // Reinitialize the queue.  The user is responsible for reclaiming thestorage
  // used by the //queue elements. 用户要负责回收用于存储队列的内存

  virtual void clear() = 0;

  // Place an element at the rear of the queue.在队尾添加元素”it”

  // it: The element being enqueued.

  virtual void enqueue(const E&) = 0;

  // Remove and return element at the front of the queue.删除并返回队首元素

  // Return: The element at the front of thequeue.

  virtual E dequeue() = 0;

  // Return: A copy of the frontelement.返回队首元素

  virtual const E& frontValue() const = 0;

  // Return: The number of elements in thequeue.返回队列长度

  virtual int length() const = 0;
};
