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
    char nextGreatestLetter(vector<char> &letters, char target)
    {

        char res;

        int start = 0;
        int end = letters.size() - 1;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (letters[mid] == target)
            {

                start = mid + 1;
            }

            else if (letters[mid] < target)
            {
                start = mid + 1;
            }

            else if (letters[mid] > target)
            {
                res = mid;
                end = mid - 1;
            }
        }

        return res;
    }
};

int main()
{
    IOS;
}