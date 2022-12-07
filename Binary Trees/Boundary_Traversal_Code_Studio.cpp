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

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
// Left Nodes without the leaf nodes
void traverseLeft(TreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {

        return;
    }

    ans.push_back(root->data);

    if (root->left != NULL)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}
// Leaf nodes
void traverseLeaf(TreeNode<int> *root, vector<int> &ans)
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

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
// Right nodes without the leaf nodes
void traverseRight(TreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right != NULL)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{

    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }
    // If leaf node then not pushing the data in answer
    if (root->left != NULL || root->right != NULL)
    {

        ans.push_back(root->data);
    }
// Traversing the left && storing left in ans without leaf nodes
    traverseLeft(root->left, ans);
// Traversing leaf && storing leafs in ans
    traverseLeaf(root, ans);
// Traversing the right && storing right in ans without leaf nodes
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    IOS;
}