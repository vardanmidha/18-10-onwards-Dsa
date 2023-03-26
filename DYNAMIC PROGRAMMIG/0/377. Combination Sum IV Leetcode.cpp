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
    int solve(vector<int> &nums, int ind, int target, vector<int> &dp)
    {

        if (target == 0)
        {
            return dp[target] = 1;
        }

        // if (ind==0)
        // {
        //     return dp[target]  = nums[0] == target;
        // }

        if (dp[target] != -1)
        {
            return dp[target];
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target >= nums[i])
            {

                ans += solve(nums, ind, target - nums[i], dp);
            }
        }

        return dp[target] = ans;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {

        vector<int> dp(target + 1, -1);

        return solve(nums, nums.size() - 1, target, dp);
    }
};

int main()
{
    IOS;
}