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

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {

        int start = 0;
        int end = n - 1;
        int out = 0;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (isBadVersion(mid) == true)
            {

                out = mid;
                end = mid - 1;
            }

            else if (isBadVersion(mid) == false)
            {

                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return out;
    }
};

int main()
{
    IOS;
}