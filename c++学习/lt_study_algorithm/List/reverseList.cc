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
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

class Solution1 {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    } else if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};

int main() {
  srand(time(NULL));

  ListNode* head = new ListNode(0);
  ListNode* head1 = new ListNode(0);
  ListNode* curr = head;
  ListNode* curr1 = head1;

  // initialize;
  int n;
  cin >> n;
  int x, last = 0;

  for (int i = 0; i < n; i++) {
    x = int(rand() % 101);
    curr->next = new ListNode(x);
    curr = curr->next;
    last = x;
  }
  for (int i = 0; i < n - 1; i++) {
    x = int(rand() % 101);
    curr1->next = new ListNode(x);
    curr1 = curr1->next;
    last = x;
  }

  curr = head->next;
  curr1 = head1->next;

  cout << "first List :" << endl;
  for (int i = 0; i < n; i++) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  cout << "second List :" << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << curr1->val << " ";
    curr1 = curr1->next;
  }
  cout << endl;

  Solution1 myAns;

  curr = myAns.mergeTwoLists(head, head1)->next->next;

  for (int i = 0; i < 2 * n - 2; i++) {
    cout << curr->val << " ";
    curr = curr->next;
  }

  return 0;
}
