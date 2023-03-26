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
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // Code here

        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (matrix[i][j] == -1)
                {

                    matrix[i][j] = 1e9;
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {

        // if (matrix[i][i] <0)
        // {

        //     Negative cycle exists
        // }

        // }

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main()
{
    IOS;
}