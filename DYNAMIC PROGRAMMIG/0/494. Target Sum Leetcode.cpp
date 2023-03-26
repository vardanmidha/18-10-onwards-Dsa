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
    int Memoization(int ind, vector<int> &nums, int target, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {

            if (ind == 0 && target == 0)
            {
                return dp[ind][target] = 2;
            }
            if (target == 0 || nums[0] == target)
            {
                return dp[ind][target] = 1;
            }

            return dp[ind][target] = 0;
        }

        int notPick = Memoization(ind - 1, nums, target, dp);

        int pick = 0;

        if (target >= nums[ind])
        {
            pick = Memoization(ind - 1, nums, target - nums[ind], dp);
        }

        return dp[ind][target] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        int k = (sum - target) / 2;

        if ((sum - target) < 0 || (sum - target) & 1)
        {
            return 0;
        }

        return Memoization(n - 1, nums, k, dp);
    }
};

int main()
{
    IOS;
}