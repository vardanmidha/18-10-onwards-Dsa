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

// LINK TO PROBLEM

/*
https://leetcode.com/problems/combination-sum/
*/
//  iF WE ARE DOING WITH PICK AND NOT-PICK APPROACH , WE SIMPLY HAVE TO APPLY THE BASE CASE AS INDEX >= SIZE
//  ELSE WE NEED TO FIGURE OUT WHAT THE BASE CASE WOULD BE , IN MOST CASES ABOVE BASE CASE IS USED.
class Solution
{
public:
    void helper(vector<int> &arr, int index, int target, vector<int> out, vector<vector<int>> &ans)
    {

        if (index >= arr.size())
        {

            if (target == 0)
            {

                ans.push_back(out);
            }
            return;
        }

        helper(arr, index + 1, target, out, ans);

        if (target >= arr[index])
        {
            out.push_back(arr[index]);

            helper(arr, index, target - arr[index], out, ans);
        }
    }

    // OR FIRST WE WILL PICK THEN NOT PICK THE ELEMENT APPROACH

    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {

        vector<vector<int>> ans;

        vector<int> out;

        helper(arr, 0, target, out, ans);

        return ans;
    }
};

int main()
{
    IOS;
}