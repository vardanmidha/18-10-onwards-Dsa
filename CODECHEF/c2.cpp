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

int main()
{
    IOS;

    int t;

    cin >> t;

    while (t--)
    {

        int a, b;
        cin >> a >> b;

        if (a * 5 > b * 2)
        {
            cout << "Chocolate" << endl;
        }

        else if (a * 5 == b * 2)
        {
            cout << "Either" << endl;
        }
        else
        {
            cout << "Candy" << endl;
        }
    }
}