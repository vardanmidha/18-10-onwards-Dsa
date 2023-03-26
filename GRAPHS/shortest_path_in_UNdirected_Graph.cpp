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
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {

        // Create adj list first

        vector<int> adj[N];

        for (auto it : edges)
        {

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(N, INT_MAX);

        queue<pair<int, int>> q;

        q.push({src, 0});
        dist[src] = 0;

        // vector<int> ans;

        while (!q.empty())
        {

            auto itr = q.front();
            q.pop();

            int node = itr.first;
            int wt = itr.second;

            for (auto it : adj[node])
            {

                if (dist[it] == INT_MAX)
                {

                    dist[it] = wt + 1;

                    q.push({it, wt + 1});
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

int main()
{
    IOS;
}