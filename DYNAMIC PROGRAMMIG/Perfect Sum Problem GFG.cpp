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

    int mod = 1e9 + 7;

private:
    int Space_Optimise(int ind, int arr[], int n, int tar)
    {

        vector<int> prev(tar + 1, 0);

        prev[0] = 1;
        prev[arr[0]] = 1;

        if (arr[0] == 0)
        {
            prev[0] = 2;
        }

        for (int ind = 1; ind < n; ind++)
        {
            // Dummy vector
            vector<int> curr(tar + 1, 0);
            curr[0] = 1;
            for (int k = 0; k <= tar; k++)
            {

                int notPick = prev[k];

                int pick = 0;

                if (arr[ind] <= k)
                {
                    pick = prev[k - arr[ind]];
                }

                curr[k] = (pick + notPick) % mod ;
            }

            prev = curr;
        }
    }

    private:
        int Tabulation(int ind, int arr[], int n, int tar, vector<vector<int>> &dp)
        {

            dp[0][0] = 2;

            for (int i = 0; i < n; i++)
            {
                dp[i][0] = 1;
            }
            dp[0][arr[0]] = 1;

            for (int ind = 1; ind < n; ind++)
            {
                for (int k = 0; k <= tar; k++)
                {

                    int notPick = dp[ind - 1][k];
                    int pick = 0;

                    if (k >= arr[ind])
                    {

                        pick = dp[ind - 1][tar - arr[ind]];
                    }

                    dp[ind][k] = (pick + notPick) % mod;
                }
            }

            return dp[n - 1][tar];
        }

    private:
        int Memoization(int ind, int arr[], int n, int tar, vector<vector<int>> &dp)
        {

            // Here Base case would be different , since arr[i] =0 for handling 0 cases.

            if (ind == 0)
            {

                if (arr[0] == 0 && tar == 0)
                {
                    return 2;
                }

                else if (arr[0] == tar || tar == 0)
                {
                    return 1;
                }

                return 0;
            }

            int notPick = Memoization(ind - 1, arr, n, tar, dp);
            int pick = 0;
            if (tar >= arr[ind])
            {
                pick = Memoization(ind - 1, arr, n, tar - arr[ind], dp);
            }

            return dp[ind][tar] = pick + notPick;
        }

    private:
        int solve(int ind, int arr[], int n, int tar)
        {

            if (tar == 0)
            {
                return 1;
            }
            if (ind == 0)
            {
                if (arr[0] == tar)
                {
                    return 1;
                }

                return 0;
            }

            int notPick = solve(ind - 1, arr, n, tar);
            int pick = 0;
            if (tar >= arr[ind])
            {

                pick = solve(ind - 1, arr, n, tar - arr[ind]);
            }

            return pick + notPick;
        }

    public:
        int perfectSum(int arr[], int n, int sum)
        {

            // Recursion only

            // return solve(n - 1, arr, n, sum);

            vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

            // Memoization        //

            // return Memoization(n - 1, arr, n, sum, dp);

            // return Tabulation(n - 1, arr, n, sum, dp);

            return Space_Optimise(n - 1, arr, n, sum);
        }
    };

    int main()
    {
        IOS;
    }