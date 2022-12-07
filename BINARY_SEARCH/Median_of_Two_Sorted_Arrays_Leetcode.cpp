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

// Dry run on
// Nums1 = [7,12,14,15,16]
// Nums2 = [1,2,3,4,9,11]

class Solution
{

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        // Making first array as the smallest in size , as it reduces the no. of operations in code which leads to decrease in
        // time complexity , i.e  O(Log(min(n1 , n2)));
        // Where n1 and n2 are sizes of nums1 and nums2.

        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int left1, left2, right1, right2;

        int start = 0;

        // Here end = n1 , not n1-1 . as the cuts which we are going to make , will be one less so for that.
        // Dry run
        int end = n1;

        while (start <= end)
        {

            int cut1 = start + (end - start) / 2;

            int cut2 = (n1 + n2) / 2 - cut1;

            // Checking for left1

            if (cut1 == 0)
            {

                left1 = INT_MIN;
            }

            else
            {

                left1 = nums1[cut1 - 1];
            }

            // Checking for left2
            if (cut2 == 0)
            {

                left2 = INT_MIN;
            }

            else
            {

                left2 = nums2[cut2 - 1];
            }

            // Checking for right1
            if (cut1 == n1)
            {

                right1 = INT_MAX;
            }
            else
            {
                right1 = nums1[cut1];
            }

            // Checking for right2
            if (cut2 == n2)
            {

                right2 = INT_MAX;
            }
            else
            {

                right2 = nums2[cut2];
            }

            if (left1 <= right2 && left2 <= right1)
            {

                // If length is even
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(left1, left2) + min(right1, right2)) / 2;
                }
                // If lenght is odd

                else
                {
                    return max(left1, left2);
                }
            }

            else if (left1 > right2)
            {

                end = cut1 - 1;
            }
            else
            {
                start = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main()
{
    IOS;
}