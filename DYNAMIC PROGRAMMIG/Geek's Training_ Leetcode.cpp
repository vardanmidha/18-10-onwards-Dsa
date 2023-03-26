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
    int Space_Optimisation(vector<vector<int>> &points, vector<int> &prev)
    {

        // We only require last here
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][1], points[0][0]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 0; day < points.size(); day++)
        {

            for (int last = 0; last < 4; last++)
            {
                int maxi = 0;
                // Temporary vector
                vector<int> temp1(4, 0);

                for (int task = 0; task < 3; task++)
                {

                    if (task != last)
                    {

                        int point = points[day][task] + prev[task];
                        maxi = max(maxi, point);
                    }
                }

                temp1[last] = maxi;

                prev = temp1;
            }
        }

        return prev[3];
    }

private:
    int Tabulation(vector<vector<int>> &points, vector<vector<int>> &dp)
    {

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < points.size(); day++)
        {
            for (int last = 0; last < 4; last++)
            {
                int maxi = 0;

                dp[day][last] = 0;

                for (int task = 0; task < 3; task++)
                {

                    if (task != last)
                    {

                        int point = points[day][task] + dp[day - 1][task];

                        maxi = max(maxi, point);
                    }
                }

                dp[day][last] = maxi;
            }
        }

        return dp[points.size() - 1][3];
    }

private:
    int Memoization(int days, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {

        if (days == 0)
        {

            int maxi = 0;

            for (int i = 0; i < 3; i++)
            {

                if (last != i)
                {

                    maxi = max(maxi, points[0][i]);
                }

                return dp[days][last] = maxi;
            }
        }

        if (dp[days][last] != -1)
        {
            return dp[days][last];
        }

        int maxi = 0;

        for (int i = 0; i < 3; i++)
        {

            if (i != last)
            {

                int possible = points[days][i] + Memoization(days - 1, i, points, dp);

                maxi = max(maxi, possible);
            }
        }

        return dp[days][last] = maxi;
    }

private:
    int solve(vector<vector<int>> &points, int ind, int last)
    {

        if (ind == 0)
        {
            int maxi = 0;
            for (int i = 0; i < 3; i++)
            {

                if (i != last)
                {

                    maxi = max(maxi, points[0][i]);
                }
            }

            return maxi;
        }

        int maxi = 0;

        for (int i = 0; i < 3; i++)
        {

            if (i != last)
            {

                int point = points[ind][last] + solve(points, ind - 1, i);

                maxi = max(point, maxi);
            }
        }

        return maxi;
    }

public:
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        // Simply recursion
        // return solve(points, n - 1, 3);

        vector<vector<int>> dp(n, vector<int>(4, -1));
        int days = n - 1;
        int last = 3;

        // Memoization

        // return Memoization(days, last, points, dp);

        // Tabulation

        // return Tabulation(points, dp);

        // Space optimised
        vector<int> prev(4, 0);
        return Space_Optimisation(points, prev);
    }
};

int main()
{
    IOS;
}