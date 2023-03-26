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
    int Tabulation(int i, int j, vector<vector<int>> &dp, int m, int n)
    {
    }

private:
    int memoization(int i, int j, vector<vector<int>> &dp)
    {

        if (i == 0 && j == 0)
        {
            return dp[i][j] = 1;
        }

        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = memoization(i - 1, j, dp);
        int left = memoization(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

private:
    int solve2(int i, int j, int m, int n)
    {

        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }

        if (i > m - 1 || j > n - 1)
        {
            return 0;
        }

        int right = solve2(i + 1, j, m, n);
        int down = solve2(i, j + 1, m, n);

        return right + down;
    }

private:
    int solve(int m, int n, vector<vector<int>> &grid)
    {

        if (m == 0 && n == 0)
        {
            return 1;
        }

        if (m < 0 || n < 0)
            return 0;

        int up = solve(m - 1, n, grid);
        int left = solve(m, n - 1, grid);

        return up + left;
    }

public:
    int uniquePaths(int m, int n)
    {

        // vector<vector<int>> grid;

        // return solve(m-1 , n-1 , grid);

        // Recursion fom 0 to n-1

        // return solve2(0 , 0 , m , n);

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Memoization

        return memoization(m - 1, n - 1, dp);
    }
};

int main()
{
    IOS;
}