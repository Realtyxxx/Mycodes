/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 *
 * https://leetcode-cn.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (29.61%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    34.9K
 * Total Submissions: 117.5K
 * Testcase Example:
 '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n'
 +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 *
 * 在链表类中实现这些功能：
 *
 *
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val 
 的节点。如果 index
 * 等于链表的长度，则该节点将附加到链表的末尾。如果 index
 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 *
 *
 *
 *
 * 示例：
 *
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 *
 *
 */

// @lc code=start

class MyLinkedList {
public:
  /** Initialize your data structure here. */
  struct myListNode {
    int val;
    myListNode *next;
    myListNode(int x) : val(x), next(nullptr) {}
  };
  MyLinkedList() {
    _dummyNode = new myListNode(0);
    _size = 0;
  }

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    if (index > _size - 1 || index < 0) {
      return -1;
    }
    myListNode *curr = _dummyNode->next;
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }
    return curr->val;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    myListNode *newHead = new myListNode(val);
    newHead->next = _dummyNode->next;
    _dummyNode->next = newHead;
    _size++;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    myListNode *curr = _dummyNode;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = new myListNode(val);
    _size++;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (index > _size)
      return;
    myListNode *curr = _dummyNode;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    myListNode *newNode = new myListNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
    ++_size;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index >= _size || index < 0)
      return;
    myListNode *curr = _dummyNode;
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }
    myListNode *tmp = curr->next;
    curr->next = curr->next->next;
    delete tmp;
    _size--;
  }

private:
  myListNode *_dummyNode;
  int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
