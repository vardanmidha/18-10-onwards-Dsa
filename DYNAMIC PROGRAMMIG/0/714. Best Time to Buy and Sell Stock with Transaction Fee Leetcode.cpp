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
    int Tabulation(vector<int> &arr, int n, int fee, vector<vector<int>> &dp)
    {

        dp[n][0] = dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {

                int profit = 0;

                if (canBuy == 1)
                {
                    // 2 options -- 1) Buy  ,,,, 2) Not-Buy

                    // If we are buying we need to subtract the value on that day.

                    int buy = -arr[i] + dp[i + 1][0];
                    int notBuy = 0 + dp[i + 1][1];
                    profit = max(buy, notBuy);
                }
                // We can't buy on current day
                // We have bought already
                else
                {
                    // 2 options -- 1)Sell ,,, 2) Not-Sell
                    int sell = arr[i] + dp[i + 1][1] - fee;
                    int notSell = 0 + dp[i + 1][0];

                    profit = max(sell, notSell);
                }

                dp[i][canBuy] = profit;
            }
        }

        return dp[0][1];
    }

private:
    int Memoization(int ind, int canBuy, vector<int> &arr, vector<vector<int>> &dp, int n, int fee)
    {

        // BAse case:
        // ind == prices.size();
        if (ind == n)
        {

            return 0;
        }

        if (dp[ind][canBuy] != -1)
        {
            return dp[ind][canBuy];
        }

        int profit = 0;

        // We can buy on current day
        if (canBuy == 1)
        {
            // 2 options -- 1) Buy  ,,,, 2) Not-Buy

            // If we are buying we need to subtract the value on that day.

            int buy = -arr[ind] + Memoization(ind + 1, 0, arr, dp, n, fee);
            int notBuy = 0 + Memoization(ind + 1, 1, arr, dp, n, fee);
            profit = max(buy, notBuy);
        }
        // We can't buy on current day
        // We have bought already
        else
        {
            // 2 options -- 1)Sell ,,, 2) Not-Sell
            int sell = arr[ind] + Memoization(ind + 1, 1, arr, dp, n, fee) - fee;
            int notSell = 0 + Memoization(ind + 1, 0, arr, dp, n, fee);

            profit = max(sell, notSell);
        }

        return dp[ind][canBuy] = profit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {

        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2, -1));

        // return Memoization(0, 1, prices, dp, n, fee);
    
    
vector<vector<int>> dp(n+1 , vector<int> (2,0));

return Tabulation(prices , n , fee , dp);
    
    
    }
};

int main()
{
    IOS;
}