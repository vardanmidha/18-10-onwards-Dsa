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
size.resize(n+1 , 1);
        rank.resize(n + 1, 0);

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
class Solution
{

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int cnt = 0;
        int n = isConnected.size();
        vector<pair<int, int>> edges;

        // Converting adj matrix into edges....--
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (isConnected[i][j] == 1)
                {

                    edges.push_back({i, j});
                }
            }
        }

        Disjoint ds(n);

        for (auto &&it : edges)
        {

            int u = it.first;
            int v = it.second;

            ds.union_By_rank(u, v);
        }

        // for (int i = 0; i < n - 1; i++)
        // {
        //     if (ds.findPar(i) != ds.findPar(i + 1))
        //     {

        //         cnt++;
        //     }
        // }

        for (int i = 0; i < n; i++)
        {

            if (ds.findPar(i) == i)
            {
                /* code */
                cnt++;
            }
        }

        return cnt;
        // unordered_set<int> st;

        // for (int i = 0; i < n; i++)
        // {

        //     st.insert(ds.findPar(i));
        // }

        // // return cnt;

        // return st.size();
    }
};

int main()
{
    IOS;
}