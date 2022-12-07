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
    int searchInsert(vector<int> &nums, int target)
    {

        if (target < nums[0])
        {

            return 0;
        }

        else
        {

            int start = 0;
            int end = nums.size() - 1;

            while (start <= end)
            {

                int mid = start + (end - start) / 2;

                if (nums[mid] == target)
                {
                    return mid;
                }

                if (target > nums[mid - 1] && target < nums[mid] && mid - 1 >= 0)
                {

                    return mid;
                }

                else if (target > nums[mid])
                {

                    start = mid + 1;
                }

                else
                {
                    end = mid - 1;
                }
            }
        }
        return 0;
    }
};

int main()
{
    IOS;
}