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

bool Tabulation(vector<int> &nums, int n, vector<vector<bool>> &dp, int k)
{

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool notPick = dp[ind - 1][target];

            bool pick = false;

            if (target >= nums[ind])
            {
                pick = dp[ind - 1][target - nums[ind]];
            }

            dp[ind][target] = pick || notPick;
        }
    }

    return dp[n - 1][k];
}

int minSubsetSumDifference(vector<int> &nums, int n)
{

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += nums[i];
    }
    int k = ans / 2;

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    Tabulation(nums, n, dp, k);

    int mini = INT_MAX;

    for (int i = 0; i < k; i++)
    {

        if (dp[n - 1][i] == true)
        {

            int s1 = i;

            int s2 = ans - i;
            int possible = abs(s2 - s1);

            mini = min(mini, possible);
        }
    }

    return mini;
}

int main()
{
    IOS;
}