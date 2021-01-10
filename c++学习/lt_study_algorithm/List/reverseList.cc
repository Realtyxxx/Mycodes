// 反转链表
// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively or recursively. Could you
// implement both?

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnnhm6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/* //efinition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

//栈、双链表、递归

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
//栈
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    stack<ListNode*> myst;
    while (head != NULL) {
      myst.push(head);
      head = head->next;
    }
    ListNode* ans = new ListNode(0);
    ListNode* temp;
    ans->next = myst.top();

    myst.pop();
    while (!myst.empty()) {
      temp->next = myst.top();
      myst.pop();
    }
    head = ans->next;
    delete ans;
    return head;
  }
};

int main() {
  ListNode* head;
  head->next = new ListNode(0);
  delete head->next;
  return 0;
}
