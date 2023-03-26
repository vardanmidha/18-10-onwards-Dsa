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

private:
    void dfsTopo(int node, vector<pair<int, int>> adj[], vector<int> &vis, int M, stack<int> &st)
    {

        vis[node] = 1;

        for (auto it : adj[node])
        {

            if (!vis[it.first])
            {
                dfsTopo(it, adj, vis, M, st);
            }
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        vector<pair<int, int>> adj[M + 1];

        for (int i = 0; i < M; i++)
        {

            adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        }

        vector<int> vis(M, 0);
        stack<int> st;

        dfsTopo(0, adj, vis, M, st);

        vector<int> dist(M, INT_MAX);

        while (!st.empty())
        {

            int top = st.top();
            st.pop();

            for (auto it : adj[top])
            {

                int v = it.first;
                int wt = it.second;

                if (dist[top] + wt < dist[v])
                {
                    dist[v] = dist[top] + wt;
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