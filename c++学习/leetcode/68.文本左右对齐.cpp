/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 *
 * https://leetcode-cn.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (45.69%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 31.6K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text",
 * "justification."]\n16'
 *
 * 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 *
 * 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 '
 * ' 填充，使得每行恰好有 maxWidth 个字符。
 *
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 *
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 *
 * 说明:
 *
 *
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 *
 *
 * 示例:
 *
 * 输入:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 *
 *
 * 示例 2:
 *
 * 输入:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。
 * ⁠ 第二行同样为左对齐，这是因为这行只包含一个单词。
 *
 *
 * 示例 3:
 *
 * 输入:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<int> wordsLength;
    vector<string> res;
    int n = words.size();
    for (int i = 0; i < n; i++) {
      wordsLength.push_back(words[i].size());
    }
    int i = 0;
    while (i < n) {
      int begin = i;
      int end = i;
      int length = maxWidth;

      while (length > 0 && i < n) {
        if (i >= 14) cout << "!!!" << length - wordsLength[i] - (end - begin) << endl;
        if (length - wordsLength[i] - (end - begin) >= 0) {
          length -= wordsLength[i];
          i++;
          end++;
        } else
          break;
      }

      string temp;

      if (end == n) {
        while (begin < end) {
          temp += words[begin];
          // cout << temp << endl;
          begin++;
          if (begin < end) {
            temp += ' ';
          }
        }
        int len = maxWidth - temp.size();
        for (int k = 0; k < len; k++) temp += ' ';
        res.push_back(temp);
        break;
      }

      int divisor = end - begin - 1;
      if (divisor == 0) {
        temp += words[begin];
        int len = maxWidth - temp.size();
        for (int k = 0; k < len; k++) temp += ' ';
        res.push_back(temp);
        continue;
      }
      int spaces = length / divisor;
      int residue = length % divisor;
      if (residue == 0) {
        while (begin < end) {
          temp += words[begin];
          begin++;
          if (begin != end) {
            for (int k = 0; k < spaces; k++) temp += ' ';
          }
        }
      } else {
        while (begin < end) {
          temp += words[begin];
          begin++;
          if (begin != end) {
            if (residue > 0) {
              for (int k = 0; k < spaces + 1; k++) temp += ' ';
              residue--;
            } else
              for (int k = 0; k < spaces; k++) temp += ' ';
          }
        }
      }
      res.push_back(temp);
    }
    return res;
  }
};
// @lc code=end

int main() {
  vector<string> words;
  words = {"Science", "is", "what",       "we",   "understand", "well",
           "enough",  "to", "explain",    "to",   "a",          "computer.",
           "Art",     "is", "everything", "else", "we",         "do"};
  /* int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    words.push_back(temp);
    // cout << i << endl;
  }
  cout << "input over" << endl; */
  /* words.push_back("This");
  words.push_back("is");
  words.push_back("an");
  words.push_back("example");
  words.push_back("of");
  words.push_back("text");
  words.push_back("justification.");
 */
  /* for (int i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  } */

  Solution my;
  vector<string> ans = my.fullJustify(words, 20);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}