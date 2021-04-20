#ifndef LIST

#define LIST

template <typename E>
class List {  // List ADT 抽象数据类型定义

 private: 
  void operator=(const List&) {}  // Protect assignment

  List(const List&) {}  // Protect copy constructor

 public:
  List() {}  // Default constructor 构造函数

  virtual ~List() {}  // Base destructor 析构函数

  // Clear contents from the list, to make itempty. 清空列表中的内容

  virtual void clear() = 0;

  // Insert an element at the current location.

  // item: The element to be inserted 在当前位置插入元素item

  virtual void insert(const E& item) = 0;

  // Append an element at the end of the list.

  // item: The element to be appended 在表尾添加元素item

  virtual void append(const E& item) = 0;

  // Remove and return the current element.

  // Return: the element that was removed. 删除当前元素，并将其作为返回值

  virtual E remove() = 0;

  // Set the current position to the start ofthe
  // list.将当前位置设置为顺序表起始处

  virtual void moveToStart() = 0;

  // Set the current position to the end of thelist. 将当前位置设置为顺序表末尾

  virtual void moveToEnd() = 0;

  // Move the current position one step left.No change

  // if already at beginning. 将当前位置左移一步，如果当前位置在首位就不变

  virtual void prev() = 0;

  // Move the current position one step right.No change

  // if already at end. 将当前位置右移一步，如果当前位置在末尾就不变

  virtual void next() = 0;

  // Return: The number of elements in thelist. 返回列表当前的元素个数

  virtual int length() const = 0;

  // Return: The position of the currentelement. 返回当前元素的位置

  virtual int currPos() const = 0;

  // Set current position.

  // pos: The position to make current. 将当前位置设置为pos

  virtual void moveToPos(int pos) = 0;

  // Return: The current element. 返回当前元素

  virtual const E& getValue() const = 0;
};

#endif