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
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int maxi = 0;
        // int m= times[0].size();

        // Create Adj list

        vector<pair<int, int>> adj[n + 1];

        for (auto &&it : times)
        {

            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        dist[k] = 0;

        while (!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();

            int dis = itr.first;
            int node = itr.second;

            for (auto &&it : adj[node])
            {

                int v = it.first;
                int wt = it.second;

                if (dis + wt < dist[v])
                {
                    dist[v] = dis + wt;
                    pq.push({dis + wt, v});
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            maxi = max(maxi, dist[i]);
        }

        if (maxi == INT_MAX)
        {

            return -1;
        }

        return maxi;
    }
};

int main()
{
    IOS;
}