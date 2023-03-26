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
    bool Space_Optimise(int ind, int k, vector<int> &nums, int n)
    {

        vector<bool> prev(n, false);
        prev[0] = true;
        prev[nums[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> curr(n, false);
            curr[0] = true;
            for (int tar = 1; tar <= k; tar++)
            {

                bool notPick = prev[tar];
                bool pick = false;
                if (tar >= nums[ind])
                {
                    pick = prev[tar - nums[ind]];
                }

                curr[tar] = pick || notPick;
            }

            prev = curr;
        }

        return prev[k];
    }

private:
    bool Tabulation(int ind, int k, vector<int> &nums, vector<vector<bool>> &dp, int n)
    {

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 0; tar <= k; tar++)
            {

                bool notpick = dp[ind - 1][k];
                bool pick = false;

                if (tar >= nums[ind])
                {
                    pick = dp[ind - 1][tar - nums[ind]];
                }

                dp[ind][tar] = pick || notpick;
            }
        }

        return dp[n - 1][k];
    }

private:
    bool Memoization2(int ind, int k, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (k == 0)
        {
            return dp[ind][k] = true;
        }

        if (ind == 0)
        {
            if (k == nums[0])
            {
                return dp[ind][k] = true;
            }

            return dp[ind][k] = false;
        }

        if (dp[ind][k] != -1)
        {
            return dp[ind][k];
        }

        bool notPick = Memoization2(ind - 1, k, nums, dp);

        bool pick = false;
        if (k >= nums[ind])
        {

            pick = Memoization2(ind - 1, k + nums[ind], nums, dp);
        }
        return dp[ind][k] = pick || notPick;
    }

private:
    bool solve(int ind, int k, int ans, vector<int> &nums)
    {

        if (k == ans - k)
        {
            return true;
        }

        if (ind == 0)
        {
            if (k + nums[0] == ans - (k - nums[0]))
            {
                return true;
            }

            return false;
        }

        bool notPick = solve(ind - 1, k, ans, nums);

        bool pick = solve(ind - 1, k + nums[ind], ans, nums);

        return pick || notPick;
    }

public:
    bool canPartition(vector<int> &nums)
    {

        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans += nums[i];
        }

        if (ans % 2 == 1)
        {
            return false;
        }

        int k = ans / 2;

        // return solve(n - 1, 0, ans, nums);

        // vector<vector<int>> dp(n + 1, vector<int>(ans + 1, -1));

        // return Memoization2(n - 1, k, nums, dp);

        vector<vector<bool>> dp(n + 1, vector<bool>(ans + 1, false));

        // return Tabulation(n - 1, k, nums, dp, n);

return Space_Optimise(n-1 , k , nums , n);

    }
};

int main()
{
    IOS;
}