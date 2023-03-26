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

class Disjoint
{

    vector<int> rank, parent , size;

public:
    Disjoint(int n)
    {

        rank.resize(n + 1, 0);
size.resize(n+1 , 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // Function to check parent
    int findPar(int node)
    {

        if (node == parent[node])
        {
            return node;
        }
        // Below doing Path compression....
        return parent[node] = findPar(parent[node]);
    }
    // We can also do by union_by_size , but this seems easy and t.c remains same...
    void union_By_rank(int u, int v)
    {

        int up_u = findPar(u);

        int up_v = findPar(v);

        // if (up_v == up_v)
        // {
        //     return ;
        // }

        if (rank[u] < rank[v])
        {

            parent[up_u] = up_v;
        }

        else if (rank[v] > rank[u])
        {

            parent[up_v] = up_u;
        }

        else
        {

            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }

    void Union_By_Size(int u, int v)
    {

        // Store ultimate parents of both the nodes.
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        // 2 cases ;
        // 1- Whichever has bigger size make it as parent

        if (size[ulp_v] > size[ulp_u])
        {

            parent[ulp_u] = ulp_v;
            // And update the size
            size[ulp_v] += size[ulp_u];
        }

        else
        {

            parent[ulp_v] = ulp_u;
            // And update the size
            size[ulp_u] += size[ulp_v];
        }
    }


};
// Kruskal algo to find MST
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.

    int spanningTree(int V, vector<vector<int>> adj[])
    {

        // {wt , u , v};
        vector<pair<int, pair<int, int>>> edges;

        // Converting adj list into edges

        for (int i = 0; i < V; i++)
        {

            for (auto &&it : adj[i])
            {

                int node = i;
                int v = it[0];
                int wt = it[1];

                edges.push_back({wt, {node, v}});
            }
        }

        Disjoint ds(V);

        sort(edges.begin(), edges.end());

        int mstWt = 0;

        for (auto &&it : edges)
        {

            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findPar(u) != ds.findPar(v))
            {
                /* code */

                mstWt += wt;
                ds.union_By_rank(u, v);
            }
        }

        return mstWt;
    }
};

int main()
{
    IOS;
}