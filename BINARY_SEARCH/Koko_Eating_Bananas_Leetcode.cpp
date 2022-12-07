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
    bool isValid(vector<int> arr, int n , int h, int mid)
    {

        //  n = arr.size();
        int i = 0;
        int hr = 0;
        while (i < n)
        {

            if (arr[i] % mid != 0)
            {

                hr = hr + (arr[i] / mid) + 1;
            }

            else
            {
                hr = hr + (arr[i] / mid);
            }
            i++;
        }

        if (hr == h)
        {
            return true;
        }

        return false;
    }

public:
    int minEatingSpeed(vector<int> &arr, int h)
    {

        int n = arr.size();
        int start = 0;
        int end = *max_element(arr.begin(), arr.end());

        int res = -1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (isValid(arr, n, h, mid) == true)
            {

                res = mid;
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }
    }
};
int main()
{
    IOS;
}