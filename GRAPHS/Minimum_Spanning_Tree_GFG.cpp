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
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {

        vector<int> vis(V, 0);

        vector<pair<int, int>> mst;
        int sum = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // {Wt , Node , Parent}
        pq.push({0, {0, -1}});

        while (!pq.empty())
        {

            auto itr = pq.top();
            pq.pop();

            int wt = itr.first;
            int node = itr.second.first;
            int parent = itr.second.second;

            if (vis[node] == 1)
            {
                continue;
            }

            vis[node] = 1;


mst.push_back({node , parent});

            sum += wt;
            for (auto &&it : adj[node])
            {
                int adjNode = it[0];
                int adjwt = it[1];

                if (!vis[adjNode])
                {

                    pq.push({adjwt, {adjNode, node}});
                }
            }
        }

        return sum;
    }
};

int main()
{
    IOS;
}