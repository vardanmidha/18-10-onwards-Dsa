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
    int Memoization(vector<int> &nums, int ind, int k, int ans, int cnt, int &mini, int n, vector<vector<int>> &dp)
    {

        if (cnt == n / 2)
        {
            mini = min(mini, abs((ans - (2 * k))));

            return dp[ind][k] = mini;
        }

        if (ind == 0)
        {

            if (cnt == n / 2 - 1)
            {

                mini = min(mini, ans - abs((2 * (k + nums[0]))));
                return dp[ind][k] = mini;
            }

            return dp[ind][k] = -1;
        }

        if (dp[ind][k] != -1)
        {
            return dp[ind][k];
        }

        int notPick = Memoization(nums, ind - 1, k, ans, cnt, mini, n, dp);

        int pick = Memoization(nums, ind - 1, k + nums[ind], ans, cnt + 1, mini, n, dp);

        return dp[ind][k] = mini;
    }

private:
    bool solve(vector<int> &nums, int ind, int k, int ans, int cnt, int &mini, int n)
    {

        if (cnt == n / 2)
        {

            mini = min(mini, (ans - (2 * k)));

            return true;
        }

        if (ind == 0)
        {

            if (cnt == n / 2 - 1)
            {

                mini = min(mini, ans - (2 * (k + nums[0])));
                return true;
            }

            return false;
        }

        bool notpick = solve(nums, ind - 1, k, ans, cnt, mini, n);
        bool pick = solve(nums, ind - 1, k + nums[ind], ans, cnt + 1, mini, n);

        return pick || notpick;
    }

public:
    int minimumDifference(vector<int> &nums)
    {

        int n = nums.size();

        int mini = INT_MAX;

        int ans = 0;
        if (n & 1)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            ans += nums[i];
        }

        // solve(nums, n - 1, 0, ans, 0, mini, n);

vector<vector<int>> dp(n , vector<int>(ans+1 , -1));

Memoization(nums , n-1 , 0 , ans , 0 , mini , n , dp);
        return mini;
    }
};

int main()
{
    IOS;
}