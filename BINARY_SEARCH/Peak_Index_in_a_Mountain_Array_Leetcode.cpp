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
    int peakIndexInMountainArray(vector<int> &arr)
    {

        int start = 0;
        int end = arr.size() - 1;

        int maxi = -1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1] && mid - 1 >= 0 && mid + 1 < n)
            {

                return mid;
            }

            else if (arr[mid] > arr[mid - 1])
            {

                start = mid + 1;
            }

            else
            {
                end = mid - 1;
            }
        }

        return 0;

        return maxi;
    }
};

int main()
{
    IOS;
}