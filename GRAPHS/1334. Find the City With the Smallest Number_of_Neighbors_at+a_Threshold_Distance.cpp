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
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        // int n = edges.size();

        int limit = distanceThreshold;


        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Convert into matrix
        for (auto &&it : edges)
        {

            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

for (int i = 0; i < n; i++)
{
    dist[i][i] = 0;
}


        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    {
                        continue;
                    }

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int citycount = n;
        int cityNo = -1;

        for (int city = 0; city < n; city++)
        {

            int cnt = 0;

            for (int adjCity = 0; adjCity < n; adjCity++)
            {

                if (dist[city][adjCity] <= limit)
                {

                    cnt++;
                }
            }

            if (cnt <= citycount)
            {

                citycount = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

int main()
{
    IOS;
}