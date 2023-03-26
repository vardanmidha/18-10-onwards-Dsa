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
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, S});

        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        while (!pq.empty())
        {

            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // for (auto it : adj[node])
            // {

            for (int i = 0; i < adj[node].size(); i++)
            {

                // int v = it[0];
                // int wt = it[1];

                int v = adj[node][i][0];
                int wt = adj[node][i][1];
                if (dis + wt < dist[v])
                {

                    dist[v] = dis + wt;
                    pq.push({dis + wt, v});
                }
            }
        }

        return dist;
    }
};

int main()
{
    IOS;
}