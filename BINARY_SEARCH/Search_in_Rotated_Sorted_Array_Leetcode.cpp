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
    int search(vector<int> &nums, int x)
    {

        int start = 0;
        int end = nums.size() - 1;
        int n = nums.size();

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (nums[mid] == x)
            {
                return mid;
            }

            // Checking on left side
            if (nums[start] <= nums[mid])
            {

                if (x >= nums[start] && x <= nums[mid])
                {
                    end = mid - 1;
                }

                else
                {
                    start = mid + 1;
                }
            }

            // Checking on right side
            else
            {
                if (x >= nums[mid] && x <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    IOS;
}