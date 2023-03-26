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

int Tabulation(vector<vector<int>> &triangle, int i, int j, int m, int n, vector<vector<int>> &dp){


for (int k = 0; k < m; k++)
{
    dp[m-1][k] = triangle[m-1][k];
    
}



for (int i = m-1; i >=0; i++)
{
    for (int j = i; j >=0; j++)
    {
        
        if (i==m-1)
        {
            continue;
        }
        

int down = triangle[i][j]+ dp[i+1][j];


int dg = triangle[i][j] + dp[i+1][j+1];

dp[i][j] = min(down , dg);

    }
    
}

return dp[0][0];

}


private:
    int Memoization(vector<vector<int>> &triangle, int i, int j, int m, int n, vector<vector<int>> &dp)
    {

        if (i == n - 1)
        {
            return dp[i][j] = triangle[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int down = triangle[i][j] + Memoization(triangle, i + 1, j, m, n, dp);
        int diagonal = triangle[i][j] + Memoization(triangle, i + 1, j + 1, m, n, dp);

        return dp[i][j] = min(down, diagonal);
    }

private:
    // Simply REcursion
    int solve(vector<vector<int>> &triangle, int i, int j, int m, int n)
    {

        // BAse case
        // Question states we just need to reach last row , not necessarily at (m-1, n-1)
        if (i == n - 1)
        {
            return triangle[n - 1][j];
        }

        int down = INT_MAX;
        int diagonal = INT_MAX;

        // No need for checking conditions , as i and j will never go out.

        down = solve(triangle, i + 1, j, m, n);
        diagonal = solve(triangle, i + 1, j + 1, m, n);

        return min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int m = triangle.size();
        // We are not considering , n as  n for every row would be differenr. n= no. of cols

        int k = triangle.size() - 1;

        int n = triangle[k].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // return Memoization(triangle, 0,0, m, n, dp);
        return Tabulation(triangle, 0,0, m, n, dp);

    }
};

int main()
{
    IOS;
}