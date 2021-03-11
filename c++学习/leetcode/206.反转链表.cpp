/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (71.10%)
 * Likes:    1433
 * Dislikes: 0
 * Total Accepted:    408.2K
 * Total Submissions: 573.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 *
 * 示例:
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 *
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

/* struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
 */

//头插法
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* now = new ListNode(0);
    ListNode* prev = new ListNode(0);
    prev->next = head;
    while (prev->next) {
      ListNode* temp = prev->next->next;
      prev->next->next = now->next;
      now->next = prev->next;
      prev->next = temp;
    }
    return now->next;
  }
};
//反转指针法
/* 
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
}; */
// @lc code=end
