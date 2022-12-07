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
    int findMin(vector<int> &arr)
    {

        int start = 0;
        int end = arr.size() - 1;

        int n = arr.size();

        while (start <= end)
        {

            // This mid is same as start+end)/2 , but it is used so that memory don't overflow.
            int mid = start + (end - start) / 2;

            // This prev is used assume the mid is at 0th index and how can it compare to prev , so for 0th index prev will be considered
            // as the last index element
            int prev = (mid + n - 1) % n;

            // This next is used for last index , how last index element would be compared to next?? , So we consider next as 0th index then
            int next = (mid + 1) % n;

            // Notice the min element would be always smaller than both the neighbourhoods , that is prec and next

            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            {
                return arr[mid];
            }

            // If the original array was sorted
            else if (arr[mid] <= arr[end])
            {

                end = mid - 1;
            }

            // If the original arrays was unsorted

            else if (arr[start] <= arr[mid])
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