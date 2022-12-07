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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode *> qt;

        if (root == NULL)
        {
            return ans;
        }

        qt.push(root);
        qt.push(NULL);

        while (!qt.empty())
        {

            TreeNode *top = qt.front();
            qt.pop();

            if (top->val == NULL)
            {

                ans.push_back(temp);
                temp.clear();

                if (!qt.empty())
                {

                    qt.push(NULL);
                }
            }

            else
            {

                temp.push_back(top->val);

                if (top->left != NULL)
                {
                    qt.push(top->left);
                }
                if (top->right != NULL)
                {
                    qt.push(top->right);
                }
            }
        }

        return ans;
    }
};

int main()
{
    IOS;
}