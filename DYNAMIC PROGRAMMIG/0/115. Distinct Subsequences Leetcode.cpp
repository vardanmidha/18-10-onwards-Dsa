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
    int Space_Optimisation(string &s1, string &s2, int n1, int n2)
    {

        vector<double> prev(n2 + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n1; i++)
        {
            vector<double> curr(n2 + 1, 0);

            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {

                    curr[j] = prev[j - 1] + prev[j];
                }

                else
                {
                    curr[j] = prev[j - 1];
                }
            }

            prev = curr;
        }

        return prev[n2];
    }

private:
    int Tabulation(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp)
    {

        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {

                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }

                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n1][n2];
    }

private:
    int Memoization(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
    {

        if (ind2 < 0)
        {
            return 1;
        }
        if (ind1 < 0)
        {
            return 0;
        }

        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }

        if (s1[ind1] == s2[ind2])
        {
            return dp[ind1][ind2] = Memoization(ind1 - 1, ind2 - 1, s1, s2, dp) + Memoization(ind1 - 1, ind2, s1, s2, dp);
        }

        return dp[ind1][ind2] = Memoization(ind1 - 1, ind2, s1, s2, dp);
    }

public:
    int numDistinct(string s, string t)
    {

        int n1 = s.size();
        int n2 = t.size();

        // vector<vector<int>> dp(n1, vector<int>(n2, -1));

        // return Memoization(n1 - 1, n2 - 1, s, t, dp);

        // Tabulation
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // return Tabulation(s, t, n1, n2, dp);

return  (int)Space_Optimisation(s1 , s2 , n1 , n2);

    }
};

int main()
{
    IOS;
}