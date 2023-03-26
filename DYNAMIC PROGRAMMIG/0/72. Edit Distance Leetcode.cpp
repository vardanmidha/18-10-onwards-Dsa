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

        vector<int> prev(n2 + 1, 0);

        for (int j = 0; j <= n2; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= n1; i++)
        {
            vector<int> curr(n2 + 1, 0);
            curr[0] = i;
            for (int j = 1; j <= n2; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {

                    curr[j] = prev[j - 1];
                }
                else
                {

                    int insert = curr[j - 1] + 1;
                    int remove = prev[j] + 1;
                    int replace = prev[j - 1] + 1;

                    curr[j] = min(min(insert, remove), replace);
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

            dp[i][0] = i;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {

                if (s1[i - 1] == s2[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else
                {

                    int insert = dp[i][j - 1] + 1;
                    int remove = dp[i - 1][j] + 1;
                    int replace = dp[i - 1][j - 1] + 1;

                    dp[i][j] = min(min(insert, remove), replace);
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
            return ind1 + 1;
        }

        if (ind1 < 0)
        {
            return ind2 + 1;
        }

        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }

        // Try All Possibilities
        // Match
        if (s1[ind1] == s2[ind2])
        {
            return dp[ind1][ind2] = Memoization(ind1 - 1, ind2 - 1, s1, s2, dp);
        }

        // If Not Match
        int insert = 1 + Memoization(ind1, ind2 - 1, s1, s2, dp);
        int remove = 1 + Memoization(ind1 - 1, ind2, s1, s2, dp);
        int replace = 1 + Memoization(ind1 - 1, ind2 - 1, s1, s2, dp);

        // Return The best Choice

        return dp[ind1][ind2] = min(min(insert, remove), replace);
    }

public:
    int minDistance(string word1, string word2)
    {

        int n1 = word1.size();
        int n2 = word2.size();

        // Memoization
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));

        // return Memoization(n1 - 1, n2 - 1, word1, word2, dp);

        // Tabulation

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // return Tabulation(word1, word2, n1, n2, dp);

        // Sapce Optimsation

        return Space_Optimisation(word1, word2, n1, n2);
    }
};

int main()
{
    IOS;
}