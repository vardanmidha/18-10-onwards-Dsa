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
    int Tabulation(vector<vector<int>> &grid, int m, int n, vector<vector<vector<int>>> &dp)
    {

        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {

                if (j1 == j2)
                {
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                }
                else
                {
                    dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
                }
            }
        }

        int maxi = 0;

        for (int i = m - 2; i >= 0; i--)
        {

            for (int j1 = m - 1; j1 >= 0; j1--)
            {
                for (int j2 = m - 1; j2 >= 0; j2--)
                {

                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {

                            int possible = 0;

                            if (j1 == j2)
                            {
                                if (j1+dj1 >=0 && j1+dj1 <n && j2+dj2>=0 && j2+dj2<n)
{
                                possible = grid[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2];
}
                            }

                            else
                            {
                                if (j1+dj1 >=0 && j1+dj1 <n && j2+dj2>=0 && j2+dj2<n)
                                {
                                    
                                    
                                
                                possible = grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2];
                                }
                            }

                            maxi = max(maxi, possible);

                        }
                    }
                            dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][0];
    }

private:
    int Memoization(vector<vector<int>> &grid, int i, int j1, int j2, int m, int n, vector<vector<vector<int>>> &dp)
    {
        // Out of bound base case
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        {
            return 0;
        }

        if (i == m - 1)
        {

            if (j1 == j2)
            {
                return grid[m - 1][j1];
            }

            return grid[m - 1][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }

        int maxi = 0;

        for (int dj1 = -1; dj1 <= 1; dj1++)
        {

            for (int dj2 = -1; dj2 <= 1; dj2++)
            {

                int possible = 0;
                if (j1 == j2)
                {

                    possible = grid[i][j1] + Memoization(grid, i + 1, j1 + dj1, j2 + dj2, m, n, dp);
                }
                else
                {

                    possible = grid[i][j2] + grid[i][j1] + Memoization(grid, i + 1, j1 + dj1, j2 + dj2, m, n, dp);
                }

                maxi = max(maxi, possible);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

private:
    // Recursion will be from (0 to n-1) as Starting is fixed
    int solve(vector<vector<int>> &grid, int i, int j1, int j2, int n, int m)
    {

        // Out of bound base case
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        {
            return INT_MIN;
        }

        // BAse case
        if (i == m - 1)
        {

            if (j1 == j2)
            {
                return grid[m - 1][j1];
            }

            return grid[i][j1] + grid[i][j2];
        }

        int maxi = 0;
        // 9 combinations
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {

                int ldg = 0, down = 0, rdg = 0;
                int possible = 0;

                if (j1 == j2)
                {

                    possible = grid[i][j1] + solve(grid, i + 1, j1 + dj1, j2 + dj2, n, m);
                }
                else
                {

                    possible = grid[i][j1] + grid[i][j2] + solve(grid, i + 1, j1 + dj1, j2 + dj2 ,n, m);
                }

                maxi = max(maxi, possible);
            }
        }

        return maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        // Recursively
        // return solve(grid , 0 , 0 , n-1 , n , m);

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        // return Memoization(grid, 0, 0, n - 1, m, n, dp);


return Tabulation(grid , m , n , dp);

    }
};

int main()
{
    IOS;
}