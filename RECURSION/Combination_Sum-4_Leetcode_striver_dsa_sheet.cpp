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

public:
    int factorial(int n)
    {

        if (n == 0)
        {
            return 1;
        }

        return n * factorial(n - 1);
    }

public:
    void helper(vector<int> &arr, int ind, int tar, int &ans, int res, vector<int> out)
    {

        unordered_map<int, int> mpp;

        if (ind >= arr.size() || tar == 0)
        {
            if (tar == 0)
            {
                for (int i = 0; i < out.size(); i++)
                {
                    mpp[out[i]]++;
                }

                for (int i = 0; i < out.size(); i++)
                {

                    if (mpp[arr[i]] > 1)
                    {

                        res = factorial(out.size()) / factorial(mpp[arr[i]]);
                        mpp[arr[i]] = -1;
                        ans += res;

                        res = 0;
                    }
                }

                ans++;
            }

            return;
        }

        if (tar >= arr[ind])
        {

            out.push_back(arr[ind]);

            helper(arr, ind, tar - arr[ind], ans, res, out);

            out.pop_back();
        }

        helper(arr, ind + 1, tar, ans, res, out);
    }

public:
    int combinationSum4(vector<int> &arr, int tar)
    {

        // vector<vector<int>> ans;
        vector<int> out;
        int ans = 0;

        helper(arr, 0, tar, ans, 0, out);
    }
};

int main()
{
    IOS;
}