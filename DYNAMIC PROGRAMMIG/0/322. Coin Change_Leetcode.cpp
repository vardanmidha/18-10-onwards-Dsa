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
    int helper(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp)
    {

             if (ind == 0)
        {

            if (coins[0] == amount)
            {

                return dp[ind][amount] = 1;
            }

            return dp[ind][amount] = 0;
        }

        if (dp[ind][amount] != -1)
        {
            return dp[ind][amount];
        }

        int notPick = helper(coins, ind - 1, amount);

        int pick = INT_MAX;
        if (coins[ind] <= amount)
        {
            pick = 1 + helper(coins, ind - 1, amount - coins[ind]);
        }

        return dp[ind][amount] = min(pick, notPick);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return helper(coins, n - 1, amount, dp);
    }
};

int main()
{
    IOS;
}