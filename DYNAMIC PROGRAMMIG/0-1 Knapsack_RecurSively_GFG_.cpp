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
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {

        if (W == 0 || n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        // if (wt[0] <= W)
        // {
        //     return max(val[0] + knapSack(W - wt[0], wt, val, n - 1), knapSack(W, wt, val, n - 1));
        // }

        if (dp[n][W] != -1)
        {

            return dp[n][W];
        }

        if (wt[n - 1] <= W)
        {

            return dp[n][W] = max((val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1)), knapSack(W, wt, val, n - 1));
        }

        else
        {

            return dp[n][W] = knapSack(W, wt, val, n - 1);
        }
    }
};

// Approach -----2

class Solution
{

    int helper(int W, int wt[], int val[], int n, vector<vector<int>> dp)
    {

        if (n == 0 || W == 0)
        {
            return 0;
        }

        if (dp[n][W] != -1)
        {

            return dp[n][W];
        }

        if (wt[n - 1] <= W)
        {

            return dp[n][W] = max((val[n - 1] + helper(W - wt[n - 1], wt, val, n - 1, dp)), helper(W, wt, val, n - 1, dp));
        }

        else
        {

            return dp[n][W] = helper(W, wt, val, n - 1, dp);
        }
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        return helper(W, wt, val, n, dp);
    }
};

int main()
{
    IOS;
}