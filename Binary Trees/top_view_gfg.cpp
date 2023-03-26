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
    Node *left;
    Node *right;
};

class Solution
{

public:
    void traverseLeft(Node *root, vector<int> &ans)
    {

        if (root == NULL)
        {
            return;
        }

        if (root->left)
        {
            traverseLeft(root->left, ans);
        }
        else
        {
            traverseLeft(root->right, ans);
        }

        ans.push_back(root->data);
    }

    void traverseRight(Node *root, vector<int> &ans)
    {

        if (root == NULL)
        {
            return;
        }

        ans.push_back(root->data);

        if (root->right)
        {
            traverseRight(root->right, ans);
        }
        else
        {
            traverseRight(root->left, ans);
        }
    }

public:
    vector<int> topView(Node *root)
    {

        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        traverseLeft(root->left, ans);
        ans.push_back(root->data);
        traverseRight(root->right, ans);

        return ans;
    }
};

int main()
{
    IOS;
}