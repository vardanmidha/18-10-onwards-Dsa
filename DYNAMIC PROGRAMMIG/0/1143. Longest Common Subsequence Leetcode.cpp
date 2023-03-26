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

int Space_Optimisation(string &s1, string &s2, int n1 , int n2){


vector<int> prev(n2+1 , -1);

for (int i = 0; i <=n2; i++)
{
    
    prev[i] = 0;
}


for (int i = 1; i <=n1; i++)
{
    vector<int> curr(n2+1 , -1);
    for (int j = 1; j <=n2; j++)
    {
        
          int ans = 0;
                if (s1[i - 1] == s2[j - 1])
                {
                    ans = 1 + prev[j - 1];
                }
                else
                {
                    ans = max(prev[j], curr[j - 1]);
                }

                curr[j] = ans;

    }
    
    prev = curr;
}

return prev[n2];

}




private:
    // For tabulation dp array would be different
    // dp[1][1] states dp[0][0]  as we can't store (-ve) indexes such as dp[-1][-1]
    // We will do shifting of indexes by 1
    int Tabulation(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp, int n1, int n2)
    {

        for (int i = 0; i <= n1; i++)
        {

            dp[i][0] = 0;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = 0;
        }

        // 2 changing parameters , 2 for loops

        for (int i = 1; i <= n1; i++)
        {

            for (int j = 1; j <= n2; j++)
            {

                int ans = 0;
                if (s1[i - 1] == s2[j - 1])
                {
                    ans = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    ans = max(dp[i - 1][j], dp[i][j - 1]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[n1][n2];
    }

private:
    int Memoization(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
    {

        if (ind1 < 0 || ind2 < 0)
        {
            return dp[ind1][ind2] = 0;
        }

        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        // MAtch
        if (s1[ind1] == s2[ind2])
        {
            return dp[ind1][ind2] = 1 + Memoization(ind1 - 1, ind2 - 1, s1, s2, dp);
        }
        // Not - MAtch
        return dp[ind1][ind2] = max(Memoization(ind1 - 1, ind2, s1, s2, dp), Memoization(ind1, ind2 - 1, s1, s2, dp));
    }

private:
    // ind1 == index of string s1
    // ind2 == index of string s2
    int solve(int ind1, int ind2, string &s1, string &s2)
    {

        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        // If the last characters match , simply call 1 + f(ind1-1 , ind2-1);
        if (s1[ind1] == s2[ind2])
        {
            return solve(ind1 - 1, ind2 - 1, s1, s2) + 1;
        }

        // else

        return max(solve(ind1 - 1, ind2, s1, s2), solve(ind1, ind2 - 1, s1, s2));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int n1 = text1.length();
        int n2 = text2.size();

        // Memoization

        // vector<vector<int>> dp(n1 , vector<int>(n2 , -1));
        //  imp ------ Here dp is only of size (n1 ,n2) because in Memoization , we don't need to store (-ve) indexes in dp array
        // return Memoization(n1-1 , n2-1 , text1 , text2 , dp);

        // Tabulation

        // SIze of dp(n1+1 , n2+1) as shifting of indexes by 1 , dp[1][0] indicates i at 0th index and j at -1th index.
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // return Tabulation(n1 - 1, n2 - 1, text1, text2, dp, n1, n2);


return Space_Optimisation(text1 , text2 , n1 , n2);
    }
};

int main()
{
    IOS;
}