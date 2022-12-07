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
    int First_Occurence(vector<int> &nums, int target)
    {

        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {

                ans = mid;

                end = mid - 1;
            }

            else if (nums[mid] > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }

public:
    int last_occurence(vector<int> &nums, int target)
    {

        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {

                ans = mid;

                start = mid + 1;
            }

            else if (nums[mid] > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }

public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());

        vector<int> ans;

        int start = First_Occurence(nums, target);
        int end = last_occurence(nums, target);

        while (start <= end)
        {
            ans.push_back(start);
            start++;
        }

        return ans;
    }
};
int main()
{
    IOS;
}