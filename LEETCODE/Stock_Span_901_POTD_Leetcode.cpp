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

class StockSpanner
{
public:
    StockSpanner()
    {
    }

    int next(int price)
    {

        stack<pair<int, int>> st;

        int cnt = 1;

        while (!st.empty() && st.top() <= price)
        {
            cnt = cnt + st.top().second;
            st.pop();
        }

        st.push({price, cnt});

        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{
    IOS;
}