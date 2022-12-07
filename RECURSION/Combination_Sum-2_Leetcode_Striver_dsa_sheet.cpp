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
    void helper_better(vector<int> &arr, int index, int target, vector<vector<int>> &ans, vector<int> &out)
    {

        if (target == 0 || index >= arr.size())
        {
            if (target == 0)
            {
                ans.push_back(out);
            }
        }

        for (int i = index; i < arr.size(); i++)
        {

            if (i > index && arr[i] == arr[i - 1])
            {
                continue;
            }

            if (arr[i] > target)
            {
                break;
            }

            out.push_back(arr[i]);

            helper_better(arr, i, target - arr[i], ans, out);
            out.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {

        vector<vector<int>> ans;
        vector<int> out;

        sort(arr.begin(), arr.end());

        helper_better(arr, 0, target, ans, out);

        return ans;
    }
};

int main()
{
    IOS;
}