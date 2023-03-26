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
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);

        pq.push({0, S});
        dist[S] = 1;

        while (!pq.empty())
        {

            auto itr = pq.top();
            pq.pop();

            int node = itr.second;
            int dis = itr.first;

            for (auto it : adj[node])
            {

                int v = it[0];
                int wt = it[1];

                if (dis + wt < dist[v])
                {

                    dist[v] = dis + wt;

                    pq.push({dis + wt, v});
                }
            }
        }

        return dis;
    }
};

// By sets (the optimal one)

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        set<pair<int, int>> st;

        st.insert({0, S});

        vector<int> dis(V, INT_MAX);

        dist[S] = 0;

        while (!st.empty())
        {

            auto itr = *(st.begin());

            int node = itr.second;
            int dis = itr.first;

            st.erase(itr);

            for (auto it : adj[node])
            {

                int v = it[0];
                int wt = it[1];

                if (dis + wt < dist[v])
                {

                    if (dist[v] != INT_MAX)
                    {

                        if (dist[v] != INT_MAX)
                        {

                            st.erase({dis[v], v});
                        }

                        dist[v] = dis + wt;

                        st.insert({dis + wt, v});
                    }
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