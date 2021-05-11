/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.30%)
 * Likes:    912
 * Dislikes: 0
 * Total Accepted:    175.7K
 * Total Submissions: 316.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 * 示例:
 *
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 *
 */

// @lc code=start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) {
      return combinations;
    }
    unordered_map<char, string> phoneMap{
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string combination;
    backtrack(combinations, phoneMap, digits, 0, combination);
    return combinations;
  }
  void backtrack(vector<string> &combinations,
                 const unordered_map<char, string> &phoneMap,
                 const string &digits, int index, string &combination) {
    if (index == digits.length()) {
      combinations.push_back(combination);
    } else {
      char digit = digits[index];
      const string &letters = phoneMap.at(digit);
      for (const char &letter : letters) {
        combination.push_back(letter);
        backtrack(combinations, phoneMap, digits, index + 1, combination);
        combination.pop_back();
      }
    }
  }
};
// @lc code=end
