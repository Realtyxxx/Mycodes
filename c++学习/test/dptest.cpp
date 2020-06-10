#include<iostream>
#include<vector>
#include<string>
using namespace std;

// int longestValidParentheses(string s){
//     int left = 0;
//     int len=s.size();
//     vector<int> dp(len, 0);
//     for(int i=0;i<len;++i){
//         if(s[i]==')'&&left==0){
//             dp[i]=0;
//         }else if(s[i]=='('){
//             if(i!=0)
//                 dp[i]=dp[i-1];
//             ++left;
//         }else if(left!=0&&s[i]==')'){
//             dp[i]=dp[i-1]+2;
//             --left;               
//         }
//     }
//     for(int i=0;i<len;++i)
//         cout<<dp[i]<<' ';
//     return 0;
// }



int main(){
    string a="(()";
    // longestValidParentheses(a);
    if(a[2]==')') cout<<"true";
    return 0;
}