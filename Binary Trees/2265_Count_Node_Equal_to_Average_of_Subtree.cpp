#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
#include"TreeNode_leetcode.h"
using namespace std ;

class Solution {


public :


int cntNodes(TreeNode *root)
{


if (root==NULL)
{
    return 0;
}

return 1 + cntNodes(root->left) + cntNodes(root->right);



}
public:

int total(TreeNode *root){

if (root==NULL)
{
    return 0;
}

int ans = root->val;

ans += total(root->left) + total(root->right);

return ans;

}

public:
    int averageOfSubtree(TreeNode* root) {
        

int tot = total(root);
int cnt = cntNodes(root);

int avg = tot/cnt;



if (root==NULL)
{
    return -1;
}



if (root->data == avg)
{
    ans 
}



    }
};


int main()
{
    IOS;
    

}