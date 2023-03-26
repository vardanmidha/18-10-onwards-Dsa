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
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> dist(n + 1, INT_MAX);

        vector<int> parent(n + 1);

        for (int i = 1; i < n + 1; i++)
        {

            parent[i] = i;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<pair<int, int>> adj[n + 1];

        for (auto it : edges)
        {

            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        pq.push({0, 1});

        dist[1] = 0;

        while (!pq.empty())
        {

            auto itr = pq.top();
            pq.pop();

            int node = itr.second;
            int dis = itr.first;

            for (auto it : adj[node])
            {

                int v = it.first;
                int wt = it.second;

                if (dis + wt < dist[v])
                {
                    dist[v] = dis + wt;

                    parent[v] = node;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[n] == INT_MAX)
        {
            return {-1};
        }

        vector<int> ans;

        int temp = n;

        while (parent[temp] != temp)
        {

            ans.push_back(temp);
            temp = parent[temp];
        }

        ans.push_back(1);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    IOS;
}