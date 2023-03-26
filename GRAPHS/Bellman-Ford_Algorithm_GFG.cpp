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
    // It works for negative cycles detection
    // It works for negative weights also.

    // We need to do n-1 iterations for shortest distance.
    // If at Nth (last) iteration the dist still decreases on any node , then there exists a negative cycle
    int mod = 1e8;
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {

        vector<int> dist(V, 1e8);
        dist[S] = 0;

        for (int i = 0; i < V - 1; i++)
        {

            for (auto &&it : edges)
            {

                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] + wt < dist[v] && dist[u] != 1e8)
                {

                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto &&it : edges)
        {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] + wt < dist[v] && dist[u] != 1e8)
            {

                return {-1};
            }
        }

        return dist;
    }
};

int main()
{
    IOS;
}