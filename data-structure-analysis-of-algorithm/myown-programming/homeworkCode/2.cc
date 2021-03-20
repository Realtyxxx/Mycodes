
4.1 :
    // assume the list name is mylist ,and it was construct by "list<int>
    // mylist;"

mylist.moveToStart();
while (mylist.getvalue() != 15) mylist.next();
mylist.remove();

4.6 :
    // assume the LList name is myl
    template <typename E>
void invert(LList<E>&myl) {
  link<E> *insertAt = tail;
  link<E> *removeAt = head;
  while (removeAt != insertAt) {
    link<E> *it = removeAt;
    removeAt = removeAt->next;
    insertAt->next = new link<E>(it->element, insertAt->next);
    delete it;
  }
  head = insertAt;
  curr = insertAt; 
  while (curr->next != nullptr) curr = curr->next;
  tail = curr;
}
//思想：从头到尾不断的将最前到元素插入到原始队列最末尾元素之后，即可将整个链表倒置
//此处利用两个指针，一个指向删除的位置，一个指向插入位置来定位操作位置，利用一次遍历即可完成。
//所以时间复杂度为O(n)

4.18 :
void invert(queue<E> &Q, stack<E> &S) {
  while (!Q.length()) {
    S.push(Q.dequeue());
  }
  while (!S.length()) {
    Q.enqueue(S.pop());
  }
}
