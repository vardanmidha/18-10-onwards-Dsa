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

int Memoization(int ind, vector<int> &price, vector<int> &weight, int W, vector<vector<int>> &dp)
{

    if (ind == 0)
    {

        return dp[ind][W] = (W / weight[0]) * price[0];
    }

    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    int notPick = Memoization(ind - 1, price, weight, W, dp);
    int pick = 0;
    if (W >= weight[ind])
    {

        pick = price[ind] + Memoization(ind , price, weight, W - weight[ind], dp);
    }

    return dp[ind][W] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{

    int W = n;

    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    {
        weight[i] = i + 1;
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    return Memoization(n - 1, price, weight, W, dp);
}

int main()
{
    IOS;
}