// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
// #include <algorithm>

using namespace std;

int longestValidParentheses(string s)
{
    int len = s.length();

    // cout<<len<<endl;

    int max = 0;
    // vector<int>dp(len,0);
    for (int j = 0; j < len; ++j)
    {
        stack<char> mid, last;
        for (int i = j; i < len; ++i)
        {

            // cout<<s[i]<<" ";

            if (s[i] == '(')
            {
                mid.push(s[i]);
                // cout << mid.top() << endl;
            }
            if (s[i] == ')')
            {
                // cout << mid.top() << endl;
                if (!mid.empty() && mid.top() == '(')
                {
                    // cout << "enter" << endl;

                    last.push(mid.top());

                    // cout << last.top() << " ";
                    // cout<<mid.size()<<endl;
                    mid.pop();
                    // cout<<mid.size()<<endl;

                    last.push(s[i]);

                    // cout << last.top() << " ";
                    if (mid.empty())
                    {
                        max = (max > last.size()) ? max : last.size();
                    }
                }
                else
                {
                    mid.push(s[i]);
                }
            }
        }
        // cout << max;
    }

    return max;
}

int main()
{
    string a = "())";
    cout << longestValidParentheses(a) << endl; 
    return 0;
}