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
    int Memoization(int ind, int canBuy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
    {

        if (cap == 2)
        {
            return 0;
        }
        if (ind == arr.size())
        {
            return 0;
        }

        if (dp[ind][canBuy][cap] != -1)
        {
            return dp[ind][canBuy][cap];
        }

        int profit = 0;

        if (canBuy == 1)
        {

            int buy = -arr[ind] + Memoization(ind + 1, 0, cap, arr, dp);
            int notBuy = 0 + Memoization(ind + 1, 1, cap, arr, dp);
            profit = max(buy, notBuy);
        }
        else
        {

            int sell = arr[ind] + Memoization(ind + 1, 1, cap + 1, arr, dp);
            int notSell = 0 + Memoization(ind + 1, 0, cap, arr, dp);

            profit = max(sell, notSell);
        }
        return dp[ind][canBuy][cap] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        // Initially can Buy
        int canBuy = 1;
        // Capacity
        int cap = 0;

        // memoization

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return Memoization(0, canBuy, cap, prices, dp);
    }
};

int main()
{
    IOS;
}