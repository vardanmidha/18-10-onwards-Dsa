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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {

        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string, int> mpp;

        sort(accounts.begin(), accounts.end());

        for (int i = 0; i < n; i++)
        {

            for (int j = 1; j < n; j++)
            {

                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end())
                {
                    // Assigning parents to particular string
                    mpp[mail] = i;
                }

                else
                {
                    ds.union_By_rank(i, mpp[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for (auto &&it : mpp)
        {

            string mail = it.first;
            int node = ds.findPar(it.second);

            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {

            if (mergedMail[i].size() == 0)
            {
                continue;
            }

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            // Storing the name first

            temp.push_back(accounts[i][0]);

            for (auto &&it : mergedMail[i])
            {

                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    IOS;
}