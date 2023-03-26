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
    int Tabulation(int ind, int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {

        for (int i = wt[0]; i <= W; i++)
        {

            dp[0][i] = val[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int weight = 0; weight <= W; weight++)
            {

                int notPick = dp[ind - 1][weight];
                int pick = INT_MIN;
                if (weight >= wt[ind])
                {

                    pick = val[ind] + dp[ind - 1][weight - wt[ind]];
                }

                dp[ind][weight] = max(pick, notPick);
            }
        }

        return dp[n - 1][W];
    }

private:
    int Memoization(int ind, int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {

            int notpick = 0;
            int pick = 0;
            if (wt[0] <= W)
            {
                pick = val[0];
            }

            return dp[ind][W] = max(pick, notpick);
        }

        if (dp[ind][W] != -1)
        {
            return dp[ind][W];
        }

        int notPick = Memoization(ind - 1, W, wt, val, n, dp);
        int pick = INT_MIN;

        if (wt[ind] <= W)
        {
            pick = val[ind] + Memoization(ind - 1, W - wt[ind], wt, val, n, dp);
        }

        return dp[ind][W] = max(pick, notPick);
    }

private:
    int helper(int ind, int W, int wt[], int val[], int n)
    {

        if (ind == 0)
        {

            int notpick = 0;
            int pick = 0;
            if (wt[0] <= W)
            {
                pick = val[0];
            }

            return max(pick, notpick);
        }

        int notPick = helper(ind - 1, W, wt, val, n);
        int pick = INT_MIN;

        if (wt[ind] <= W)
        {
            pick = helper(ind - 1, W - wt[ind], wt, val, n);
        }

        return max(pick, notPick);
    }

public:
    int knapSack(int W, int wt[], int val[], int n)
    {

        // return helper(n - 1, W, wt, val, n);
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        // return Memoization(n - 1, W, wt, val, n, dp);
        return Tabulation(n - 1, W, wt, val, n, dp);
    }
};

int main()
{
    IOS;
}