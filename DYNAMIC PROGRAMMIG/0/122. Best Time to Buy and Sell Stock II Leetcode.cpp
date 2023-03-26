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
int Space_Optimisation(vector<int> &arr , int n){

vector<int> next(2,0);
next[0] = next[1] = 0;

 for (int ind = n - 1; ind >= 0; ind--)
        {
vector<int> curr(2,0);
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {

                int profit = 0;

                if (canBuy == 1)
                {

                    int buy = -arr[ind] + next[0];
                    int notBuy = 0 + next[1];

                    profit = max(buy, notBuy);
                }

                else
                {

                    int sell = arr[ind] + next[1];
                    int notSell = 0 + next[0];

                    profit = max(sell, notSell);
                }

                curr[canBuy] = profit;
         
            }
        next = curr;
        }

}



private:
    int Tabulation(vector<int> &arr, vector<vector<int>> &dp, int n)
    {

        for (int i = 0; i < 2; i++)
        {
            dp[n][i] = 0;
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {

            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {

                int profit = 0;

                if (canBuy == 1)
                {

                    int buy = -arr[ind] + dp[ind + 1][0];
                    int notBuy = 0 + dp[ind + 1][1];

                    profit = max(buy, notBuy);
                }

                else
                {

                    int sell = arr[ind] + dp[ind + 1][1];
                    int notSell = 0 + dp[ind + 1][0];

                    profit = max(sell, notSell);
                }

                dp[ind][canBuy] = profit;
            }
        }

        return dp[0][1];
    }

private:
    int Memoization(int ind, int canBuy, vector<int> &arr, vector<vector<int>> &dp, int n)
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

            int buy = -arr[ind] + Memoization(ind + 1, 0, arr, dp, n);
            int notBuy = 0 + Memoization(ind + 1, 1, arr, dp, n);
            profit = max(buy, notBuy);
        }
        // We can't buy on current day
        // We have bought already
        else
        {
            // 2 options -- 1)Sell ,,, 2) Not-Sell
            int sell = arr[ind] + Memoization(ind + 1, 1, arr, dp, n);
            int notSell = 0 + Memoization(ind + 1, 0, arr, dp, n);

            profit = max(sell, notSell);
        }

        return dp[ind][canBuy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        // Initially buy == 1 , you can buy
        int canBuy = 1;

        // buy==0 (You cannot buy on next days).
        // buy ==1 (You can buy on next days).

        // Memoization

        // vector<vector<int>> dp(n, vector<int>(2, -1));

        // return Memoization(0, canBuy, prices, dp, n);

        // Tabulation

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // return Tabulation(prices, dp, n);
    
    // Space Optimisation

    return Space_Optimisation(prices , n);
    
    }
};

int main()
{
    IOS;
}