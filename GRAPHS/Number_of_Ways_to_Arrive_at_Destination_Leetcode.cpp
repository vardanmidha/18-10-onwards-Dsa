#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define v1 vector<long long>
#define v2 vector<vector<long long>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    int  countPaths(long long n, vector<vector<long long>> &roads)
    {
        long long mod = 1e9 + 7;
        vector<pair<long long, long long>> adj[n + 1];

        for (auto &&it : roads)
        {

            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, 1e15);
        vector<long long> ways(n, 1e15);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        // Dist , Node
        pq.push({0, 0});

        while (!pq.empty())
        {

            auto itr = pq.top();
            pq.pop();

            long long dis = itr.first;
            long long node = itr.second;

            for (auto &&it : adj[node])
            {

                long long v = it.first;
                long long wt = it.second;

                if (wt + dis < dist[v])
                {

                    dist[v] = wt + dis;
                    ways[v] = 1;

                    pq.push({wt + dis, v});
                }

                else if (dis + wt == dist[v])
                {

                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }

        if (ways[n-1] ==0){
            return -1;
        }

        return ways[n-1] %mod;
    }
};

long long main()
{
    IOS;
}