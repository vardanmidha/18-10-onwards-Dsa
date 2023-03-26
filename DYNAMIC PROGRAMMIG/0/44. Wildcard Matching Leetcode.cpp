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

private:
    bool Memoization(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
    {

        // bAse cases----

        if (ind1 < 0 && ind2 < 0)
        {
            return dp[ind1][ind2] = true;
        }

        if (ind1 >= 0 && ind2 < 0)
        {

            return false;
        }

        if (ind1 < 0 && ind2 >= 0)
        {

            for (int i = 0; i <= ind2; i++)
            {
                if (s2[ind2] != '*')
                {
                    return false;
                }
                return true;
            }
        }

        if (dp[ind1][ind2] != -1)
        {

            return dp[ind1][ind2];
        }

        // MAtch

        if (s1[ind1] == s2[ind2] || s2[ind2] == '?')
        {
            return dp[ind1][ind2] = Memoization(ind1 - 1, ind2 - 1, s1, s2, dp);
        }

        // if s2[ind2] =='*'

        if (s2[ind2] == '*')
        {

            return dp[ind1][ind2] = Memoization(ind1 - 1, ind2, s1, s2, dp) || Memoization(ind1, ind2 - 1, s1, s2, dp);
        }

        // Not-Match

        return dp[ind1][ind2] = false;
    }

public:
    bool isMatch(string s, string p)
    {

        int n1 = s.size();
        int n2 = p.size();

        // memoization
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return Memoization(n1 - 1, n2 - 1, s, p, dp);
    }
};

int main()
{
    IOS;
}