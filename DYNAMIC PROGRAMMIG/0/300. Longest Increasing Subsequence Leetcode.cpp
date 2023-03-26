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
    // Shifting of indexes

private:
    int Tabulation(vector<int> &nums, vector<vector<int>> &dp, int n)
    {

        for (int i = 0; i <= n; i++)
        {
            dp[n][i] = 0;
        }

        for (int i = n - 1; i >= 0; i--)
        {

            for (int prev_ind = i - 1; prev_ind >= 0; prev_ind--)
            {

                int notPick = dp[i + 1][prev_ind + 1];

                int pick = 0;
                if (prev_ind == -1 || nums[i] > nums[prev_ind])
                {

                    pick = 1 + dp[i + 1][i + 1];
                }
                dp[i][prev_ind + 1] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }

private:
    int Memoization(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp, int n)
    {

        if (ind == n)
        {
            return 0;
        }
        if (dp[ind + 1][prev + 1] != -1)
        {
            return dp[ind + 1][prev + 1];
        }

        int notPick = Memoization(ind + 1, prev, nums, dp, n);

        int pick = 0;
        if (prev == -1 || nums[ind] > nums[prev])
        {

            pick = 1 + Memoization(ind + 1, ind, nums, dp, n);
        }

        return dp[ind + 1][prev + 1] = max(pick, notPick);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();

        // memoization

        // Shifting of indexes

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int prev = -1;

        // return Memoization(0, prev, nums, dp, n);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return Tabulation(nums, dp, n);
    }
};

int main()
{
    IOS;
}