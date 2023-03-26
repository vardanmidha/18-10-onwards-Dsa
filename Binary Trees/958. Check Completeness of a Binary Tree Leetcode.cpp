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
    bool isCompleteTree(TreeNode *root)
    {

        if (root == NULL)
        {
            return false;
        }

        if (!root->left && !root->right)
        {

            return true;
        }

        queue<pair<TreeNode *, int>> q;

        q.push(make_pair(root, 0));
        int cnt = 0;

        int out = 1;
        vector<int> ans;

        int req = 0;
        while (!q.empty())
        {

            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                auto itr = q.front();
                q.pop();
                TreeNode *top = itr.first;
                int ind = itr.second;

                if (ind != i)
                {

                    return false;
                }

                i++;

                if (top->left)
                {

                    q.push({top->left, 2 * ind + 1});
                }

                if (top->right)
                {
                    q.push({top->right, 2 * ind + 2});
                }
            }
        }

        return true;
    }
};


int main()
{
    IOS;
}