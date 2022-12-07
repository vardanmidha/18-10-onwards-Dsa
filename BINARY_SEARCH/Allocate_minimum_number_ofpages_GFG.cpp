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
    // Function to check if its valid
    bool isValid(int *arr, int n, int k, int max)
    {

        int student = 1;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {

            sum = sum + arr[i];

            if (sum > max)
            {

                student++;
                sum = arr[i];
            }
        }

        if (student > k)
        {

            return false;
        }

        return true;
    }

public:
    // Function to find minimum number of pages.
    int findPages(int arr[], int n, int k)
    {

        int res = -1;

        int start = *max_element(arr, arr + n);

        int end = accumulate(arr, arr + n, 0);

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (isValid(arr, n, m, mid) == true)
            {

                res = mid;
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }

        return res;
    }
};
int main()
{
    IOS;
}