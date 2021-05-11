/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
 *
 * https://leetcode-cn.com/problems/merge-in-between-linked-lists/description/
 *
 * algorithms
 * Medium (77.97%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 8.5K
 * Testcase Example:  '[0,1,2,3,4,5]\n3\n4\n[1000000,1000001,1000002]'
 *
 * 给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
 *
 * 请你将 list1 中第 a 个节点到第 b 个节点删除，并将list2 接在被删除节点的位置。
 *
 * 下图中蓝色边和节点展示了操作后的结果：
 *
 * 请你返回结果链表的头指针。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
 * 输出：[0,1,2,1000000,1000001,1000002,5]
 * 解释：我们删除 list1 中第三和第四个节点，并将 list2
 * 接在该位置。上图中蓝色的边和节点为答案链表。
 *
 *
 * 示例 2：
 *
 *
 * 输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 =
 * [1000000,1000001,1000002,1000003,1000004]
 * 输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
 * 解释：上图中蓝色的边和节点为答案链表。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3
 * 1
 * 1
 *
 *
 */

// @lc code=start

//   Definition for singly-linked list.
#include <iostream>

// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    int len = b - a + 1;
    ListNode *la = list1;
    ListNode *lb = list1;
    while (len--) {
      lb = lb->next;
    }
    for (int i = 0; i < a - 1; ++i) {
      la = la->next;
      lb = lb->next;
    }
    ListNode *ltemp = la->next;
    la->next = list2;
    ListNode *l2end = list2;
    while (l2end->next != nullptr)
      l2end = l2end->next;
    la->next = list2;
    l2end->next = lb->next;
    lb->next = nullptr;
    return list1;
  }
};
// @lc code=end
