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

// In this ques by dijsktra only queue is required not priority queue because----
// 1---- It is a grid
// 2---- It is increasing by unit distance.
class Solution
{

private:
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {0, 0}});

        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty())
        {

            auto itr = q.front();
            int dis = itr.first;
            int row = itr.second.first;
            int col = itr.second.first;

            q.pop();

            for (int i = 0; i < 8; i++)
            {

                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc])
                {

                    // Check if we reach the destination..

                    if (nr == n - 1 && nc == m - 1)
                    {
                        return dis + 1;
                    }

                    q.push({dis + 1, {nr, nc}});
                }
            }
        }


        return -1;
    }
};

int main()
{
    IOS;
}