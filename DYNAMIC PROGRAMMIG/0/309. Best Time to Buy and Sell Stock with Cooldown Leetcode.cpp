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
    int Memoization(int ind, int canBuy, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (ind >= arr.size())
        {
            return 0;
        }
        if (dp[ind][canBuy] != -1)
        {
            return dp[ind][canBuy];
        }

        int profit = 0;
        if (canBuy == 1)
        {
            int buy = Memoization(ind + 1, 0, arr, dp) - arr[ind];
            int notBuy = Memoization(ind + 1, 1, arr, dp);

            profit = max(buy, notBuy);
        }

        else
        {
            int sell = Memoization(ind + 2, 0, arr, dp) + arr[ind];
            int notSell = Memoization(ind + 1, 0, arr, dp);

            profit = max(sell, notSell);
        }

        return dp[ind][canBuy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        int canBuy = 1;
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return Memoization(0, canBuy, prices, dp);
    }
};

int main()
{
    IOS;
}