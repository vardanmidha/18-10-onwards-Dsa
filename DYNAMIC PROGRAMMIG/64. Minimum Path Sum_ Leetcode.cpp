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
    int Space_Optimised(vector<vector<int>> &grid, int n, int m)
    {

        if (grid.size() == 0)
        {
            return 0;
        }
        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++)
        {

            vector<int> temp(m, 0);

            for (int j = 0; j < m; j++)
            {

                if (i == 0 && j == 0)
                {

                    temp[j] = grid[0][0];
                    continue;
                }

                int left = INT_MAX;
                int up = INT_MAX;

                if (j - 1 >= 0)
                {
                    left = temp[j - 1];
                }
                if (i - 1 >= 0)
                {
                    up = prev[j];
                }

                temp[j] = min(left , up);

                prev = temp;
            }
        }

        return prev[m - 1];
    }

private:
    int Tabulation(vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m)
    {

        if (grid.size() == 0)
        {
            return 0;
        }

        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (i == 0 && j == 0)
                {
                    continue;
                }

                int left = INT_MAX;
                if (j - 1 >= 0)
                {

                    left = grid[i][j] + dp[i][j - 1];
                }
                int up = INT_MAX;
                if (i - 1 >= 0)
                {
                    up = grid[i][j] + dp[i - 1][j];
                }

                dp[i][j] = min(left, up);
            }
        }

        return dp[n - 1][m - 1];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // return Tabulation(grid, dp, n, m);
        return Space_Optimised(grid, n, m);
    }
};

int main()
{
    IOS;
}