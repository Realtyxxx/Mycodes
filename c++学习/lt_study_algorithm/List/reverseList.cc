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
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return head;
  }
};

int main() {
  srand(time(NULL));
  ListNode* head;
  ListNode* curr = head;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x = rand()%101;
    curr -> next = new ListNode(x);
    curr = curr->next;
  }
  curr =head;
  for(int i = 0; i < n; i++) {
    cout << curr->val;
    curr = curr->next;
  }
  Solution myans;
  myans.reverseList(head);
  curr =head;
  for(int i = 0; i < n; i++) {
    cout << curr->val;
    curr = curr->next;
  }
  return 0;
}
