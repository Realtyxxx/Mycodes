/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (45.23%)
 * Likes:    825
 * Dislikes: 0
 * Total Accepted:    187.9K
 * Total Submissions: 415.1K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 *
 * 示例 1:
 *
 * 输入: 1->2
 * 输出: false
 *
 * 示例 2:
 *
 * 输入: 1->2->2->1
 * 输出: true
 *
 *
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 */

// @lc code=start
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

// definition for singly-linked list.
/* struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 */
// answer of the questions.
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;
    ListNode* firstHalfEnd = endOfFirstHalf(head);
    ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
    // judge if Palindrome
    bool result = true;
    ListNode* p1 = head;
    ListNode* p2 = secondHalfStart;
    while (result && p1 != nullptr && p2 != nullptr) {
      if (p1->val != p2->val) {
        result = false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    // restore the list.
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    return prev;
  }

  ListNode* endOfFirstHalf(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};
// @lc code=end
