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
#include "TreeNode_leetcode.h"
using namespace std;

class Solution
{

public:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int inS, int inE, int postS, int postE)
    {

        if (inS > inE)
        {
            return NULL;
        }

        int rootData = postorder[postE];
        int rootindex = -1;

        for (int i = 0; i < postE + 1; i++)
        {

            if (rootData == inorder[i])
            {
                rootindex = i;
                break;
            }
        }

        int linS = inS;
        int linE = rootindex - 1;
        int lpostS = postS;

        int lpostE = linE - linS + lpostS;

        int rinS = rootindex + 1;
        int rinE = inE;
        int rposrS = lpostE + 1;

        int rpostE = rootindex - 1;

        TreeNode *root = new TreeNode(rootData);

        root->left = helper(inorder, postorder, linS, linE, rinS, rinE);
        root->right = helper(inorder, postorder, rinS, rinE, rposrS, rpostE);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

int main()
{
    IOS;
}