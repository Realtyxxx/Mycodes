#include <assert.h>

#include "link.h"
#include "list.h"

// This is the declaration for LList. It is split into two parts

// because it is too big to fit on one book page

// Linked list implementation

using namespace std;

template <typename E>
class LList : public List<E> {
 private:
  Link<E>* head;  // Pointer to list header 指向链表头结点

  Link<E>* tail;  // Pointer to last element 指向链表最后一个结点

  Link<E>* curr;  // Access to current element 指向当前元素

  int cnt;  // Size of list 当前列表大小

  void init() {  // Intialization helper method 初始化

    curr = tail = head = new Link<E>;

    cnt = 0;
  }

  void removeall() {
    while (head != NULL) {
      curr = head;

      head = head->next;

      delete curr;
    }
  }

 public:
  LList(int size = 100) { init(); }  // Constructor 构造函数

  ~LList() { removeall(); }  // Destructor 析构函数

  void print() const;  // Print list contents 打印列表内容

  void clear() {
    removeall();
    init();
  }  // Clear list清空列表

  // Insert "it" at current position 在当前位置插入“it”

  void insert(const E& it) {
    curr->next = new Link<E>(it, curr->next);

    if (tail == curr) tail = curr->next;  // New tail 新的尾指针

    cnt++;
  }

  void append(const E& it) {  // Append "it" to list 在列表的尾部追加“it”

    tail = tail->next = new Link<E>(it, NULL);

    cnt++;
  }

  // Remove and return current element 删除并返回当前元素

  E remove() {
    assert(curr->next != NULL);  //"Noelement" 若当前没有元素则中断程序

    E it = curr->next->element;  // Remember value 保存元素值

    Link<E>* ltemp = curr->next;  // Remember link node保存指针域信息

    if (tail == curr->next) tail = curr;  // Reset tail 重置尾指针

    curr->next = curr->next->next;  // Remove from list从列表中删除

    delete ltemp;  // Reclaim space 回收空间

    cnt--;  // Decrement the count 当前链表长度减一

    return it;
  }

  void moveToStart()  // Place curr at list start将curr设置在链表头部

  {
    curr = head;
  }

  void moveToEnd()  // Place curr at list end 将curr设置在链表尾部

  {
    curr = tail;
  }

  // Move curr one step left; no change if already at front

  // 将curr指针往前移一步；如果已经指向头部了就不需要改变

  void prev() {
    if (curr == head) return;  // No previous element 若当前指针是头指针直接返回

    Link<E>* temp = head;

    // March down list until we findthe previous element
    // 循环链表直到找到前一个元素

    while (temp->next != curr) temp = temp->next;

    curr = temp;
  }

  // Move curr one step right; no change if already at end

  //将curr指针往后移一步；如果已经指向尾部了就不需要改变

  void next()

  {
    if (curr != tail) curr = curr->next;
  }

  int length() const { return cnt; }  // Return length 返回当前列表大小

  // Return the position of the current element 返回当前元素的位置

  int currPos() const {
    Link<E>* temp = head;

    int i;

    for (i = 0; curr != temp; i++) temp = temp->next;

    return i;
  }

  // Move down list to "pos" position 向下移动到列表“pos”位置

  void moveToPos(int pos) {
    assert((pos >= 0) && (pos <= cnt));  //"Position out of range" 不在范围内

    curr = head;

    for (int i = 0; i < pos; i++) curr = curr->next;
  }

  const E& getValue() const {  // Return current element 返回当前元素

    assert(curr->next != NULL);  //"No value" 内容为空

    return curr->next->element;
  }
};
