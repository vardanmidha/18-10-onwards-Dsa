#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;



struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {


vector<int> ans;

if (root==NULL)
{
    return ans;
}


map<int  , int> mpp;
queue<pair<Node* , int>> q;

q.push(make_pair(root , 0));


while (!q.empty())
{
    
pair<Node* , int> temp = q.front();
q.pop();

Node * top = temp.first;
int hd = temp.second;

if (mpp.find(hd) == mpp.end())
{
    
    mpp[hd] = top->data;

}


if (top->left)
{
    q.push(make_pair(top->left , hd-1));
}
if (top->right)
{
    q.push(make_pair(top->right ,hd+1));
}





}




for(auto it:mpp){
    ans.push_back(it.second);
}

return ans;

    }

};
int main()
{
    IOS;
    

}