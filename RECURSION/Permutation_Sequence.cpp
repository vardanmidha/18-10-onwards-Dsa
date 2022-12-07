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
using namespace std;

class Solution
{

public:
    void solve(int ind, string &s, vector<string> &ans, int k)
    {

        if (ind >= s.size())
        {
            ans.push_back(s);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {

            swap(s[i], s[ind]);
            solve(ind + 1, s, ans, k);

            swap(s[i], s[ind]);
        }
    }

public:
    string getPermutation(int n, int k)
    {

        string s;

        vector<string> ans;

        for (char i = '1'; i <= n; i++)
        {
            s.push_back(i);
        }

        solve(0, s, ans, k);

        string out = ans[k - 1];
    }
};

int main()
{
    IOS;
}