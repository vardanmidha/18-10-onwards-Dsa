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
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        int n = flights.size();
        int m = flights[0].size();

        vector<pair<int, int>> adj[n + 1];

        for (auto &&it : flights)
        {

            // Making adjacency list

            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // stops , source , distance
        pq.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);

        while (!pq.empty())
        {

            auto itr = pq.top();
            pq.pop();

            int stops = itr.first;
            int node = itr.second.first;
            int dis = itr.second.second;

            for (auto &&it : adj[node])
            {

                int v = it.first;
                int wt = it.second;

                if (dis + wt < dist[v])
                {
                    dist[v] = dis + wt;

                    pq.push({stops + 1, {v, dis + wt}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
        {

            return -1;
        }

        return dist[dst];
    }
};

int main()
{
    IOS;
}