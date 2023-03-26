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

    int Tabulation_Space_Optimised(int n, vector<int> nums)
    {

        if (n == 0)
        {
            return 0;
        }
        // dp[0]
        int prev2 = 0;

        // dp[1]
        int prev = 0;

        for (int i = 1; i < n; i++)
        {

            int notPick = 0 + prev;

            int pick = nums[i];
            if (i > 1)
            {
                pick += prev2;
            }

            int curr = max(pick, notPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int Tabulation(int n, vector<int> nums, vector<int> dp)
    {

        if (nums.size() == 0)
        {
            return 0;
        }

        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {

            int notPick = 0 + dp[i - 1];

            int pick = nums[i];

            if (i > 1)
            {
                pick += dp[i - 2];
            }

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }

private:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> dp(n + 1, -1);

        vector<int> temp1(n - 1);
        vector<int> temp2(n - 1);

        for (int i = 0; i < n; i++)
        {

            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }

        // int choice1 = Tabulation(n, temp1, dp);
        // int choice2 = Tabulation(n, temp2, dp);



int choice1 = Tabulation_Space_Optimised(n-1 , temp1);
int choice2 = Tabulation_Space_Optimised(n-1 , temp2);
        return max(choice1, choice2);
    }
};

int main()
{
    IOS;
}