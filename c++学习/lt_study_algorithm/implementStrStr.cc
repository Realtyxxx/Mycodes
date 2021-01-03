// 实现 strStr() 函数。

// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle
// 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:

// 输入: haystack = "hello", needle = "ll"
// 输出: 2
// 示例 2:

// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
// 说明:

// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

// 对于本题而言，当 needle 是空字符串时我们应当返回 0
// 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnr003/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int len1 = haystack.size();
    int len2 = needle.size();
		if (len1 < len2)	return -1;
    for (int i = 0; i < len1; i++) {
      if (haystack[i] == needle[0]) {
        // cout << i << endl;
        int k = 0;
        for (;k+i <len1 && k < len2 && haystack[i + k] == needle[k]; k++) ;
        if (k == len2) return i;
      }
    }
    return -1;
  }
};

class Solution1 {
public:
    int strStr(string haystack, string needle) {
        int len1=haystack.length();
        int len2=needle.length();
        if(len1<len2){
            return -1;
        }
        if(len2==0){
            return 0;
        }
        for(int i=0; i<len1-len2+1; i++){
            if(haystack[i]==needle[0]){
                int j=0;
                for(; j<len2&&j<len1-i;++j){
                    if(haystack[i+j]!=needle[j]){
                        break;
                    }
                }
                if(j==len2){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  Solution a;
  cout << a.strStr(s1, s2) << endl;
  return 0;
}