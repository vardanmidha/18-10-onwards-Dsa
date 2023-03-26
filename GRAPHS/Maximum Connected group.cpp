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

public:
    vector<int> rank, parent, size;
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

class Solution
{

private:
    bool isValid(int row, int col, int n, int m)
    {

        return row >= 0 && row < n && col >= 0 && col < m;
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        // code here

        int n = grid.size();
        int m = grid[0].size();
        Disjoint ds(n * m);

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Connecting the components
                if (grid[i][j] == 0)
                {
                    continue;
                }

                for (int ind = 0; ind < 4; ind++)
                {

                    int nr = i + delRow[ind];
                    int nc = j + delCol[ind];

                    if (isValid(nr, nc, n, m))
                    {

                        if (grid[nr][nc] == 1)
                        {

                            int nodeNumber = (i * m) + j;
                            int adjNodeNumber = (nr * m) + nc;

                            ds.Union_By_Size(nodeNumber, adjNodeNumber);
                        }
                    }
                }
            }
        }

                int mx = 0;

                // 2nd step Brute Force
                // Checking for every 0
                for (int row = 0; row < n; row++)
                {

                    for (int col = 0; col < m; col++)
                    {
                        int sum = 0;

                        set<int> st;

                        if (grid[row][col] == 1)
                        {
                            continue;
                        }

                        for (int ind = 0; ind < 4; ind++)
                        {

                            int nr = row + delRow[ind];

                            int nc = col + delCol[ind];

                            if (isValid(nr, nc, n, m))
                            {

                                if (grid[nr][nc] == 1)
                                {
                                    int nodeNumber = (nr * m) + nc;
                                    st.insert(ds.findPar(nodeNumber));
                                }
                            }
                        }
                        for (auto it : st)
                        {
                            sum += ds.size[it];
                        }
                        mx = max(mx, sum + 1);
                    }
                }
            
        

        // Last Step (Final step )

        // If all elements present in the matrix are 1 , then this approach won't work.

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 0)
                {
                    cnt++;
                }
            }
        }

        if (cnt == 0)
        {

            return (m * n);
        }

        return mx;
    }
};

int main()
{
    IOS;
}