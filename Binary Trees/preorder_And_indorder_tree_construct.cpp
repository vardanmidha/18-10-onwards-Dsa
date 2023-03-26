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

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int preS, int preE, int inS, int inE)
    {

        if (inS > inE)
        {
            return NULL;
        }

        int rootindex = -1;

        int rootData = preorder[preS];

        for (int i = 0; i < preE + 1; i++)
        {

            if (rootData == inorder[i])
            {
                rootindex = i;
                break;
            }
        }

        int linS = inS;

        int linE = rootindex - 1;

        int lpreS = preS + 1;

        int lpreE = linE - linS + lpreS;

        int rinS = rootindex + 1;

        int rinE = inE;

        int rpreS = lpreE + 1;

        int rpreE = inE;

        TreeNode *root = new TreeNode(rootData);

        root->left = helper(preorder, inorder, lpreS, lpreE, linS, linE);
        root->right = helper(preorder, inorder, rpreS, rpreE, rinS, rinE);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

int main()
{
    IOS;
}