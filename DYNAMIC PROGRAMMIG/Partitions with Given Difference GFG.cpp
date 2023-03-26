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
    int Space_Optimise(int ind, vector<int> arr , int n, int tar)
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

                curr[k] = (pick + notPick) % mod;
            }

            prev = curr;
        }
    }

public:
    int countPartitions(int n, int d, vector<int> &arr)
    {

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        if (sum - d < 0 || (sum - d) & 1)
        {

            return 0;
        }

        int tar = (sum - d) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));

        return Space_Optimise(n - 1, arr, n, tar);
    }
};
int main()
{
    IOS;
}