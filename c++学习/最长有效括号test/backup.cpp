/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (30.63%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    60.9K
 * Total Submissions: 198.7K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left = 0, midtemp = 0,next=0,midbegin=0, maxnum = 0,leftbefore=0;   
        bool ifhas=false;
        int len = s.size();
        vector<int> dp(len, 0);
        for (int i = 0; i < len; ++i)
        {
            if(s[i]==')'){
                if(left==0){
                    dp[i]=0;
                    midtemp=0;
                }else{             //left!=0
                    if(s[i-1]!=')'){
                        dp[i]=dp[i-1]+2;
                    }else{
                        dp[i]=0;
                    }
                    --left;
                    if(left==0){                    //闭合了连续了之前的括号子串
                        for(int j=next;j<=i;++j){
                            dp[j]+=midtemp;
                        }
                        midtemp=dp[i];
                        next=i+1;
                    }
                    if((left!=0)&&ifhas&&!(dp[i]-dp[midbegin-1]==i-midbegin+1)&&(i+1==len)){
                        // cout<<midbegin<<" "<<left<<" "<<leftbefore<<" "<<endl;
                    
                        int n=(i-midbegin-left+leftbefore+1);
                        int l=i;
                        cout<<"n,l: "<<n<<' '<<l<<' ';
                        while(n>0){
                            dp[l]-=n;
                            --l;n-=2;}
                    
                    }
                    if(i+1!=len&&s[i+1]=='(')  ifhas=true; 
                    midbegin=i+1;
                    leftbefore=left;
                }
            }
            else if(s[i]=='('){
                if(left==0){
                    dp[i]=0;
                }else{
                    dp[i]=dp[i-1];
                }
                ++left;
            }
            cout<<i<<':'<<dp[i]<<"  ";
        };
        cout<<endl;
        for(int i=0;i<len;++i){
            cout<<dp[i]<<"  ";
            if(dp[i]>maxnum){
                maxnum=dp[i];
            }
        }
        return maxnum;
    }
};
// @lc code=end

