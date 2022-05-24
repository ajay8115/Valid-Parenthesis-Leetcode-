#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define forn for (int i = 0; i < n; i++)
#define srt(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define kk '\n'
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        stack<char> st;
        stack<int> ind;

        ind.push(-1);

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                ind.push(i);
            }
            else
            {
                if (!st.empty() and st.top() == '(')
                {
                    st.pop();
                    ind.pop();
                    maxi = max(maxi, i - ind.top());
                }
                else
                {
                    ind.push(i);
                }
            }
        }

        return maxi;
    }
};