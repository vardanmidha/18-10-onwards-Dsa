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

    vector<int> parent, rank;

public:
    Disjoint(int n)
    {

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {

        if (node == parent[node])
        {
            return node;
        }

        // Below path Compression , saves extra log(n) Time and attaches node to its ultimate parent that also reduces the height

        return parent[node] = findUltimateParent(parent[node]);
    }

    // Whenever we need to connect 2 nodes , we decide on the basis of rank.
    // Whichever node has more rank we will make that parent
    // In case the rank becomes equal of both the nodes then we can attach any and increase the rank of parent by 1.
    void UnionByRank(int u, int v)
    {

        // First we will find the ultimate parents of both the nodes.

        int ul_u = findUltimateParent(u);
        int ul_v = findUltimateParent(v);

        if (rank[ul_u] > rank[ul_v])
        {

            parent[ul_v] = ul_u;
        }

        else if (rank[ul_v] > rank[ul_u])
        {

            parent[ul_u] = ul_v;
        }

        // Else the rank of both the nodes is same..

        else
        {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }
};

class Solution

{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {

        // N = Number of Nodes
        int n = accounts.size();
        Disjoint ds(n);

        // Map is created to store the mails to their Nodes
        unordered_map<string, int> mpp;
        // {mail  , Node};

        for (int i = 0; i < n; i++)
        {

            int m = accounts[i].size();

            // We are starting from j=1 , because at [i][0] there will be names stored
            // But we need only mapping of emails.
            for (int j = 1; j < m; j++)
            {

                string mail = accounts[i][j];
                // If not present in map already
                if (mpp.find(mail) == mpp.end())
                {
                    // Node is in the from of integers.
                    int node = i;
                    mpp[mail] = node;
                    // {mpp[mail] = node}
                }

                else
                {
                    // Connected the Two Nodes , In which we have found one common email
                    ds.UnionByRank(i, mpp[mail]);
                }
            }
        }

            // Now mapping exists in map , we need to iterate through it and store ans
            // (Array of vectors)
            vector<string> MergedMails[n];

            for (auto &&it : mpp)
            {

                string mail = it.first;
                // int node = it.second;
                int node_ul = ds.findUltimateParent(it.second);
                // It would merge the vector<vector>> but still leave some empty vector<string>
                MergedMails[node_ul].push_back(mail);
            }

            // Finally store our ans.
            vector<vector<string>> ans;

            for (int i = 0; i < n; i++)
            {

                // If vector<string> is empty , don't add it skip the iteration.

                if (MergedMails[i].size() == 0)
                {
                    continue;
                }
                // else

                // We need to give the answer in sprted array

                sort(MergedMails[i].begin(), MergedMails[i].end());

                // This vector is because we also need to store the name  , which is stored at 0th index
                vector<string> temp;

                temp.push_back(accounts[i][0]);

                // Then store the mergedmail

                for (auto &&it : MergedMails[i])
                {

                    temp.push_back(it);
                }

                ans.push_back(temp);
            }

            // We can return the ans in any from , So no need to sort it.
            return ans;
        }
    };

    int main()
    {
        IOS;
    }