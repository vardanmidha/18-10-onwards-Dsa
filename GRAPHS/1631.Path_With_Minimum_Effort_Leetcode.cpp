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
// By dijkstra BFS
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {

        int n = heights.size();
        int m = heights[0].size();

        if (heights.size() == 0)
        {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        while (!pq.empty())
        {

            auto itr = pq.top();
            pq.pop();

            int dis = itr.first;
            int row = itr.second.first;
            int col = itr.second.second;

            if (row == n - 1 && col == m - 1)
            {
                return dis;
            }

            for (int i = 0; i < 4; i++)
            {

                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {

                    int newEffort = max(abs(heights[nr][nc] - heights[row][col]), dis);

                    if (newEffort < dist[nr][nc])
                    {
                        /* code */

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;

    }
};

// return dist[n - 1][m - 1];


int main()
{
    IOS;
}