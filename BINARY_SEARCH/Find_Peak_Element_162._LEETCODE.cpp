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
    int findPeakElement(vector<int> &arr)
    {

        int ans = -1;

        int n = arr.size();

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if (arr[mid] > arr[next] && arr[mid] < arr[prev])
            {
                ans = mid;
            }




else if (arr[mid-1] >= arr[mid]&& mid-1>=0)
{
    
    end = mid-1;
}

else
{
    start = mid+1;
}

         
         

        }


        return ans;
    }
};

int main()
{
    IOS;
}