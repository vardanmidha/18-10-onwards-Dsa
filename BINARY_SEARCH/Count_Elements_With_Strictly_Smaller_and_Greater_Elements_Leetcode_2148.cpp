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
    int countElements(vector<int> &nums)
    {

        int mini = *min_element(nums.begin(), nums.end());

        int maxi = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {

            mpp[nums[i]]++;
        }

        int maxf = mpp[maxi];
        int minf = mpp[mini];
        int ans = 0;

        if (maxi == mini)
        {

            ans = nums.size() - minf;
        }

        else
        {

            ans = nums.size() - maxf - minf;
        }

        return ans;

        return 0;
    }
};

int main()
{
    IOS;
}