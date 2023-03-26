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
    int Tabulation(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp)
    {

        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[n1][n2];
    }

public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {

        int n1 = n;
        int n2 = m;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        Tabulation(s1, s2, n1, n2, dp);

        int maxi = 0;
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi;
    }
};

int main()
{
    IOS;
}