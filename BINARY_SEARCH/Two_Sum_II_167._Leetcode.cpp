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
    vector<int> twoSum(vector<int> &arr, int target)
    {

        int i = 0;
        int j = arr.size() - 1;

        vector<int> ans;

        while (i < j)
        {

            if (arr[i] + arr[j] == target)
            {

                ans.push_back(i);
                ans.push_back(j);
            }

            else if (arr[i] + arr[j] > target)
            {

                j--;
            }

            else
            {
                // start ++;
                i++;
            }
        }
    return ans;
    }
};

int main()
{
    IOS;
}