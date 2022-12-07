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
    bool search(vector<int> &arr, int target)
    {

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target)
            {
                return true;
            }

            else if (arr[start] <= arr[mid])
            {

                if (target >= arr[start] && target <= arr[mid])
                {

                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            else
            {

                if (target >= arr[mid] && target <= arr[end])
                {
                    start = mid + 1;
                }

                else
                {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    IOS;
}