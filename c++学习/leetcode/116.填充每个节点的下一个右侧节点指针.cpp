/*
 * @lc app=leetcode->cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 *
 * https://leetcode-cn->com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (69->50%)
 * Likes:    461
 * Dislikes: 0
 * Total Accepted:    117->7K
 * Total Submissions: 169->4K
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 * 填充它的每个 next
 * 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next
 * 指针设置为 NULL。
 *
 * 初始状态下，所有 next 指针都被设置为 NULL。
 *
 *
 *
 * 进阶：
 *
 *
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 *
 *
 *
 *
 * 示例：
 *
 *
 *
 *
 * 输入：root = [1,2,3,4,5,6,7]
 * 输出：[1,#,2,3,#,4,5,6,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next
 * 指针，以指向其下一个右侧节点，如图 B
 * 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#'
 * 标志着每一层的结束。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数量少于 4096
 * -1000
 *
 *
 */

// @lc code=start

// Definition for a Node->
/* class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
}; */

/* class Solution {
 public:
  Node *connect(Node *root) {
    if (root == nullptr) return nullptr;
    if (root->left) root->left->next = root->right;
    if (root->right && root->next) root->right->next = root->next->left;
    root->left = connect(root->left);
    root->right = connect(root->right);
    return root;
  }
}; */
/* class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) return root;
    // cur我们可以把它看做是每一层的链表
    Node* cur = root;
    while (cur != nullptr) {
      //遍历当前层的时候，为了方便操作在下一
      //层前面添加一个哑结点（注意这里是访问
      //当前层的节点，然后把下一层的节点串起来）
      Node* dummy = new Node(0);
      // pre表示下一层节点的前一个节点
      Node* pre = dummy;

      //然后开始遍历当前层的链表
      //因为是完美二叉树，如果有左子节点就一定有右子节点
      while (cur != nullptr && cur->left != nullptr) {
        //让pre节点的next指向当前节点的左子节点，也就是把它串起来
        pre->next = cur->left;
        //然后再更新pre
        pre = pre->next;

        // pre节点的next指向当前节点的右子节点，
        pre->next = cur->right;
        pre = pre->next;
        //继续访问这一行的下一个节点
        cur = cur->next;
      }
      //把下一层串联成一个链表之后，让他赋值给cur，
      //后续继续循环，直到cur为空为止
      cur = dummy->next;
    }
    return root;
  }
}; */
//下一层节点遍历next用，cur在这一层，用上一次pre链接好，再赋值给cur
class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) return root;
    Node* cur = root;
    while (cur != nullptr) {
      Node* dummy = new Node(0);
      Node* pre = dummy;
      while (cur != nullptr && cur->left != nullptr) {
        pre->next = cur->left;
        pre = pre->next;
        pre->next = cur->right;
        pre = pre->next;
        cur = cur->next;
      }
      cur = dummy->next;
    }
    return root;
  }
};
// @lc code=end
