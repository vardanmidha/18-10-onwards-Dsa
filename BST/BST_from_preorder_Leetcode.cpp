#include <iostream>
#include <bits/stdc++.h>
#include"TreeNode_leetcode.h"
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


class Solution {


public : 
TreeNode *helper(vector<int> &preorder , int pres , int preE){


int rootData = preorder[pres];

int lend = -1;
int i=0;
while (preorder[i] > preorder[i+1])
{
    lend =i;
    i++;
}


int lstart = pres +1;
int rstart = lend +1;
int rend = preE;

TreeNode *root = new TreeNode(rootData);

root->left = helper(preorder , lstart , lend);
root->right = helper(preorder , rstart , rend);


return root;

}



public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        


if (preorder.size() ==0)
{
    return NULL;
}

return helper(preorder , 0 , preorder.size()-1);
          



    }
};



int main()
{
    IOS;
    

}