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

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{

public:
    pair<int, int> maxiandmini(Node *root)
    {

        if (root == NULL)
        {

            pair<int, int> p;
            p.first = INT_MAX;
            p.second = INT_MIN;
            return p;
        }

        pair<int, int> lans = maxiandmini(root->left);
        pair<int, int> rans = maxiandmini(root->right);

        int lmin = lans.first;
        int lmax = lans.second;
        int rmin = rans.first;
        int rmax = rans.second;

        pair<int, int> p;

        p.first = min(root->data, min(lmin, rmin));
        p.second = max(root->data, max(lmax, rmax));

        return p;
    }

public:
    int findMax(Node *root)
    {

        pair<int, int> ans = maxiandmini(root);
        return ans.second;
    }
    int findMin(Node *root)
    {

        pair<int, int> ans = maxiandmini(root);
        return ans.first;
    }
};

int main()
{
    IOS;
}