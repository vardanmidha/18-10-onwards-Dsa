#include <iostream>
#include <bits/stdc++.h>

#define vl vector<long long>
#define v1 vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#include "TreeNode_leetcode.h"
using namespace std;

// Iteratively:

class Solution
{

public:
    TreeNode *lastRight(TreeNode *root)
    {

        if (root->right == NULL)
        {
            return root;
        }

        return lastRight(root->right);
    }

public:
    TreeNode *helper(TreeNode *root, int key)
    {

        if (root->left == NULL)
        {
            return root->right;
        }

        if (root->right == NULL)
        {
            return root->left;
        }

        TreeNode *rgt = root->right;
        TreeNode *lft = lastRight(root);

        lft->right = rgt;

        return root->left;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        TreeNode *temp = root;

        if (root == NULL)
        {
            return root;
        }

        if (root->val == key)
        {

            return helper(root, key);
        }

        while (root)
        {

            if (root->val > val)
            {

                if (root->left && root->left->val == key)
                {

                    root->left = helper(root, key);

                    break;
                }

                else
                {
                    root = root->left;
                }
            }

            else
            {

                if (root->right && root->right->val == key)
                {

                    root->right = helper(root->right, key);

                    break;
                }

                else
                {
                    root = root->right;
                }
            }
        }

        return temp;
    }
};

int main()
{
    IOS;
}