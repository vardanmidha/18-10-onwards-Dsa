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
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {

        // Your code here

        long long start = 0;
        long long end = n - 1;

        long long mid;

        int ans = -1;

        while (start <= end)
        {

            mid = start + (end - start) / 2;

            if (v[mid] == x)
            {
                return mid;
            }

            else if (v[mid] < x)
            {
                ans = v[mid];
                start = mid + 1;
            }

            else if (v[mid] > x)
            {
                end = mid - 1;
            }
        }

        return ans;
    }
};
int main()
{





    IOS;


int a = floor(2.3);
int b = ceil(2.2);

cout<<a<<" "<<b;


}