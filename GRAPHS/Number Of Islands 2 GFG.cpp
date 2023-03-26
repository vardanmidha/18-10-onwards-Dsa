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

    vector<int> rank, parent;

public:
    Disjoint(int n)
    {

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
};

class Solution
{

private:
    bool isValid(int row, int col, int n, int m)
    {

        return row >= 0 && row < n && col >= 0 && col < m;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {

        // We will assign n*m size to matrix , 0-n to every element..
        // Fun(row , col) = (row*m + col)
        Disjoint ds(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> ans;

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        int cnt = 0;

        for (auto &&it : operators[i])
        {

            int row = it[0];
            int col = it[1];

            if (vis[row][col])
            {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            for (int ind = 0; ind < 4; ind++)
            {

                int adjRow = row + delRow[i];
                int adjCol = col + delCol[i];

                if (isValid(adjRow, adjCol, n, m))
                {

                    int nodeNumber = row * m + col;
                    int adjNodeNumber = adjRow * m + adjCol;

                    if (ds.findPar(nodeNumber) != ds.findPar(adjNodeNumber))
                    {
                        /* code */

                        cnt--;

                        ds.union_By_rank(nodeNumber, adjNodeNumber);
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};

int main()
{
    IOS;
}