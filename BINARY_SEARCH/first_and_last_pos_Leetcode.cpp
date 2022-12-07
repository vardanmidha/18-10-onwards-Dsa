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
    vector<int> searchRange(vector<int> &arr, int target)
    {

        int first = -1;
        int second = -1;

        vector<int> ans;

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target)
            {
                first = mid;
                end = mid - 1;
            }

            else if (arr[mid] > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }
        start = 0;
        end = arr.size() - 1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target)
            {
                second = mid;
                // end = mid -1;
                start = mid + 1;
            }

            else if (arr[mid] > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }

vector<int> ans;
ans.push_back(first);
ans.push_back(second);

return ans;

    }
};

int main()
{
    IOS;
}