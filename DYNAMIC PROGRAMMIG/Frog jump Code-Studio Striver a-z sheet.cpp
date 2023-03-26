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

// Tabulation
int solve_better(int ind, vector<int> &heights, vector<int> &dp)
{

    dp[0] = 0;

    for (int i = 1; i <= ind; i++)
    {

        int jump1 = dp[i - 1] + abs(heights[i - 1] - heights[i]);

        int jump2 = INT_MAX;

        if (i > 1)
        {

            jump2 = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(jump1, jump2);
    }

    return dp[ind];
}

// Memoization
int solve(int ind, vector<int> &heights, vector<int> &dp)
{

    if (ind == 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    // Jump with 1 step
    int jump1 = solve(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);

    // Jump with 2 steps
    // Initially storing as MAx value , because if ind==1 then this call won't happen
    int jump2 = INT_MAX;

    if (ind > 1)
    {

        jump2 = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(jump1, jump2);
}

// By recursion
int helper(int ind, vector<int> &heights)
{

    if (ind == 0)
    {
        return 0;
    }
    // Jump with 1 step
    int jump1 = helper(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);

    // Jump with 2 steps
    // Initially storing as MAx value , because if ind==1 then this call won't happen
    int jump2 = INT_MAX;

    if (ind > 1)
    {

        jump2 = helper(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    }

    return min(jump1, jump2);
}

int frogJump(int n, vector<int> &heights)
{

    if (n == 0)
    {
        return 0;
    }

    vector<int> dp(n + 1, -1);
    // index = n-1

    // Recursive
    return helper(n - 1, heights);

    // Memoization

    return solve(n - 1, heights, dp);
}

int main()
{
    IOS;
}