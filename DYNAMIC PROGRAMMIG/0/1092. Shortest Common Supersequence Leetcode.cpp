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

                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }

public:
    string shortestCommonSupersequence(string str1, string str2)
    {

        int n1 = str1.size();
        int n2 = str1.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        Tabulation(str1, str2, n1, n2, dp);

        int i = n1;
        int j = n2;

        string ans;

        while (i > 0 && j > 0)
        {

            if (str1[i - 1] == str2[j - 1])
            {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }

            else if (dp[i - 1][j] >= dp[i][j - 1])
            {

                ans.push_back(str1[i - 1]);
                i--;
            }

            else
            {
                ans.push_back(str2[j - 1]);

                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    IOS;
}