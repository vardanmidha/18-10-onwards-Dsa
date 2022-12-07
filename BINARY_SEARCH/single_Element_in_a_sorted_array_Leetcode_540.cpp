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
    int singleNonDuplicate(vector<int> &arr)
    {

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if (arr[mid] != arr[next] && arr[mid] != arr[prev])
            {

                return mid;
            }

            else if (arr[mid] == arr[prev])
            {

                int ind = mid - start;

                if (ind % 2 == 0)
                {
                    end = mid;
                }
                else
                {
                    start = mid + 1;
                }
            }

            else
            {

                int ind = end - mid;

                if (ind % 2 != 0)
                {
                    end = mid - 1;
                }

                else
                {
                    start = mid;
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