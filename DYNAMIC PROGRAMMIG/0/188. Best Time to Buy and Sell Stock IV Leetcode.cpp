#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


class Solution {

private:

 private:
    int Memoization(int ind, int canBuy, int k, vector<int> &arr, vector<vector<vector<int>>> &dp)
    {

        if (k == 0)
        {
            return 0;
        }
        if (ind == arr.size())
        {
            return 0;
        }

        if (dp[ind][canBuy][k] != -1)
        {
            return dp[ind][canBuy][k];
        }

        int profit = 0;

        if (canBuy == 1)
        {

            int buy = -arr[ind] + Memoization(ind + 1, 0, k, arr, dp);
            int notBuy = 0 + Memoization(ind + 1, 1, k, arr, dp);
            profit = max(buy, notBuy);
        }
        else
        {

            int sell = arr[ind] + Memoization(ind + 1, 1, k -1, arr, dp);
            int notSell = 0 + Memoization(ind + 1, 0, k, arr, dp);

            profit = max(sell, notSell);
        }
        return dp[ind][canBuy][k] = profit;
    }


public:
    int maxProfit(int k, vector<int>& prices) {


int n = prices.size();
 int canBuy = 1;
        // Capacity


        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));



return Memoization(0 , canBuy , k , prices , dp);

    }
};


int main()
{
    IOS;
    

}