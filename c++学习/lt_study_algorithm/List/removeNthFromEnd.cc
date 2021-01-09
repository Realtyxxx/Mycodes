// 删除链表的倒数第N个节点
// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

// Follow up: Could you do this in one pass?

//  

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
//  

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
// 相关标签
// 链表
// 双指针

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn2925/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *first, *second;
    first = head;
    second = dummy;  //为了得到前驱节点
    for (int i = 0; i < n; ++i) {
      first = first->next;
    }
    while (first) {
      first = first->next;
      second = second->next;
    }
    second->next = second->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
  }
};

// 1. delete 释放 new 分配的空间
// 2. free 释放 malloc 分配的空间
// 3. delete[] 释放 new[]分配的空间
//  	顺便说一下new在分配空间的时候同时会调用对象的构造函数，对对象进行初始化，使用malloc则只是分配内存
// 4. 调用free 之前需要检查 需要释放的指针是否为空，使用delete
// 		释放内存则不需要检查指针是否为NULL
// 5. free 和 delete 不能混用，也就是说new 分配的内存空间最好不要使用使用free
// 		来释放，malloc 分配的空间也不要使用 delete来释放