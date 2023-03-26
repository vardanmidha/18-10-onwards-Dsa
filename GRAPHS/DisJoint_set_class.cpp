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
    // Initialise size with {1}
    vector<int> rank, parent, size;

public:
    Disjoint(int n)
    {

        rank.resize(n + 1, 0);

        parent.resize(n + 1);

        size.resize(n + 1, 1);
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
    // Size will help us to know , how many nodes are present in a connected component.
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

int main()
{
    IOS;

    // Disjoint ds(6);

    // ds.union_By_rank(1, 2);

    // ds.union_By_rank(2, 3);
    // ds.union_By_rank(1, 4);

    // if (ds.findPar(3) == ds.findPar(5))
    // {
    //     /* code */

    //     cout << "Found in first"<<endl;
    // }

    // ds.union_By_rank(3, 5);

    // if (ds.findPar(3) == ds.findPar(5))
    // {
    //     /* code */

    //     cout << "Found in second";
    // }

    Disjoint ds2(6);

    ds2.Union_By_Size(1, 2);
    ds2.Union_By_Size(2, 3);
    ds2.Union_By_Size(1, 4);

    if (ds2.findPar(3) == ds2.findPar(5))
    {
        /* code */

        cout << "Found in first" << endl;
    }

    ds2.union_By_rank(3, 5);

    if (ds2.findPar(3) == ds2.findPar(5))
    {
        /* code */

        cout << "Found in second";
    }

    ds2.Union_By_Size(3, 5);
}