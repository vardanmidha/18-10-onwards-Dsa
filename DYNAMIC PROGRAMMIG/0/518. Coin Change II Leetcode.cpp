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
    int Memoization(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {

            if (amount % coins[0] == 0)
            {
                return dp[ind][amount] = 1;
            }

            return dp[ind][amount] = 0;
        }

        if (dp[ind][amount] != -1)
        {
            return dp[ind][amount];
        }

        int notPick = Memoization(ind - 1, coins, amount, dp);
        int pick = 0;
        if (amount > coins[ind])
        {
            pick = Memoization(ind, coins, amount-coins[ind], dp);
        }

        return dp[ind][amount] = pick + notPick;
    }

public:
    int change(int amount, vector<int> &coins)
    {


int n = coins.size();
vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));


return Memoization(n-1 , coins , amount , dp);

    }
};

int main()
{
    IOS;
}