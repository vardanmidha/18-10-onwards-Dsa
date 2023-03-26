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

//  A binary tree Node
struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{

public:
    void left(Node *root, vector<int> &ans)
    {

        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return;
        }

        ans.push_back(root->data);

        if (root->left != NULL)
        {
            left(root->left, ans);
        }

        else
        {
            left(root->right, ans);
        }
    }

public:
    void leaf(Node *root, vector<int> &ans)
    {

        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        leaf(root->left, ans);
        leaf(root->right, ans);
    }

public:
    void right(Node *root, vector<int> &ans)
    {

        if (root == NULL || root->right == NULL && root->left == NULL)
        {
            return;
        }

        if (root->right)
        {
            right(root->right, ans);
        }

        else
        {
            right(root->left, ans);
        }

        ans.push_back(root->data);
    }

public:
    vector<int> boundary(Node *root)
    {
        // Your code here

        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        ans.push_back(root);

        left(root->left, ans);
        leaf(root, ans);
        right(root->right, ans);

        return ans;
    }
};

int main()
{
    IOS;
}