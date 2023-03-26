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

int Memoization(int ind, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{

    if (ind == 0)
    {

        if (weight[0] <= W)
        {

            return dp[ind][W] = weight[0];
        }

        return dp[ind][W] = 0;
    }

    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    int notPick = Memoization(ind - 1, W, profit, weight, dp);

    int pick = 0;

    if (W >= weight[ind])
    {

        pick = Memoization(ind - 1, W - weight[ind], profit, weight, dp);
    }

    return max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{

    // int n = profit.size();

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    return Memoization(n - 1, w, profit, weight, dp);
}

int main()
{
    IOS;
}