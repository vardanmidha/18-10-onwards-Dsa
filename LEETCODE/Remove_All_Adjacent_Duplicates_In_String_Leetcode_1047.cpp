#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define v1 vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#include <stack>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {

        int n = s.size();

        stack<char> st;

        stack<char> rst;

        if (n == 1)
        {

            return s;
        }

        st.push(s[0]);

        for (int i = 1; i < n; i++)
        {

            if (s[i] == st.top() && !st.empty())
            {

                st.pop();
            }

            else
            {
                st.push(s[i]);
            }
        }

        if (st.size() == 0)
        {
            return "";
        }

        string out(st.size(), 'x';)

            for (int i = out.length() - 1; i >= 0; i--)
        {

            out[i] = st.top();
            st.pop();
        }

        return out;
    }
};

int main()
{
    IOS;
}