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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        vector<int> out;
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;

        if (root == NULL)
        {
            return ans;
        }

        st1.push(root);
        TreeNode *front1 = NULL;
        TreeNode *front2 = NULL;

        while (!st1.empty() || !st2.empty())
        {

            while (!st1.empty())
            {

                front1 = st1.top();

                st1.pop();

                out.push_back(front1->val);

                if (front1->left != NULL)
                {
                    st2.push(front1->left);
                }
                if (front1->right != NULL)
                {
                    st2.push(front1->right);
                }
            }

            while (!st2.empty())
            {

                front2 = st2.top();

                st2.pop();

                out.push_back(front2->val);

                if (front2->left != NULL)
                {
                    st2.push(front2->left);
                }
                if (front2->right != NULL)
                {
                    st2.push(front2->right);
                }

                /* code */
            }
        }

        ans.push_back(out);
        return ans;
    }
};

int main()
{
    IOS;
}