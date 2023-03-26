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

public:


void markParents(TreeNode *root , unordered_map<TreeNode* , TreeNode*> &parent_track , TreeNode *target)
{


queue<TreeNode*> q;

q.push(root);

while (!q.empty())
{
    
    TreeNode *front = q.front();

q.pop();

if (front->left)
{
    q.push(front->left);
    parent_track[front->left] = front;
}
if (front->right)
{
    q.push(front->right);
    parent_track[front->right] = front;
}




}






}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        


unordered_map<TreeNode* , TreeNode*> parent_track;

markParents(root , parent_track , target);


unordered_map<TreeNode* , int> visited;

visited[target] = 1;

queue<TreeNode*> q;
q.push(target);

int lvl =0;
while (!q.empty())
{
    if (lvl == k)
    {
        break;
    }
    
    lvl++;

for (int i = 0; i < q.size(); i++)
{
    
    TreeNode*front = q.front();
    q.pop();


if (front->left && !visited[front->left])
{
    /* code */

q.push(front->left);
visited[front->left] = 1;



}

if (front->right && !visited[front->right])
{
    /* code */

q.push(front->right);
visited[front->right] =1;

}

if (parent_track[front]  && !visited[parent_track[front]])
{
    /* code */

q.push(parent_track[front]);
visited[parent_track[front]] = 1;


}





}








}

vector<int> ans;

for(auto i:q){
    ans.push_back(i);
}

return ans;
    }
};



int main()
{
    IOS;
    

}