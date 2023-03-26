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

// Memoization

int memoization(vector<int> &nums, int ind, vector<int> &dp)
{

    if (nums.size() == 0)
    {
        return 0;
    }

    // 1 base case, If we reach at 0th index then definately we haven't picked 1st element So
    // We simply need to return the element on 0th index

    if (ind == 0)
    {
        return nums[0];
    }

    //

    // 2nd base case , If ind <0

    if (ind < 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int pick = nums[ind] + memoization(nums, ind - 2, dp);

    int notPick = 0 + memoization(nums, ind - 1, dp);

    return dp[ind] = max(pick, notPick);
}

// Recursively from last index
int solve_Recursively_Last_Index(vector<int> &nums, int ind, int &maxi)
{

    if (nums.size() == 0)
    {
        return 0;
    }

    // 1 base case, If we reach at 0th index then definately we haven't picked 1st element So
    // We simply need to return the element on 0th index

    if (ind == 0)
    {
        return nums[0];
    }

    //

    // 2nd base case , If ind <0

    if (ind < 0)
    {
        return 0;
    }

    int pick = nums[ind] + solve_Recursively_Last_Index(nums, ind - 2, maxi);
    int notPick = 0 + solve_Recursively_Last_Index(nums, ind - 1, maxi);

    return max(pick, notPick);
}

// Approach--1 Recursively , TLE
void helper(vector<int> &nums, int ind, int &maxi, vector<int> out, int ans)
{

    if (ind == 0)
    {

        for (int i = 0; i < out.size(); i++)
        {

            ans += out[i];
        }

        maxi = max(ans, maxi);

        return;
    }

    helper(nums, ind + 1, maxi, out, ans);

    out.push_back(nums[ind]);

    helper(nums, ind + 2, maxi, out, ans);
}

int maximumNonAdjacentSum(vector<int> &nums)
{

    vector<int> out;

    int maxi = 0;
    // Recursively TLE
    // helper(nums, 0, maxi, out, 0);

    // return maxi;

    // Recursively from last index , Better.. We can apply DP further.
    int ind = nums.size() - 1;

    vector<int> dp(ind + 2, -1);

    // return solve_Recursively_Last_Index(nums, ind, maxi)

    // By Memoization
    return memoization(nums, ind, dp);
}

int main()
{
    IOS;
}