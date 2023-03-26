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
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis)
    {

        vis[node] = 1;

        for (auto &&it : adj[node])
        {

            if (!vis[it.first])
            {
                vis[it.first] = 1;
                dfs(it.first, adj, vis);
            }
        }
    }

public:
    int minScore(int n, vector<vector<int>> &roads)
    {

        vector<vector<pair<int, int>>> adj;

        for (auto &&it : roads)
        {

            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis);

        int mini = INT_MAX;
        for (auto &&it : roads)
        {

            if (vis[it[0]] == 1)

                mini = min(mini, it[2]);
        }

        return mini;
    }
};

int main()
{
    IOS;
}