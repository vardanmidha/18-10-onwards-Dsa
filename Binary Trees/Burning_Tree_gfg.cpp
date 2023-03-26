#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;





    



struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {



    public:

    Node*findTarget(Node*root , int tar){


if (root==NULL)
{
    return NULL;
}


if (root->data == tar)
{
    return root;
}

Node *a = findTarget(root->left , tar);
Node *b = findTarget(root->right , tar);



if (a==NULL)
{
    return b;
}

return a;

// return root;

    }


public :


void markParents(Node *root , unordered_map<Node* , Node*> &parent_track )
{


queue<Node*> q;

q.push(root);

while (!q.empty())
{
    
    Node *curr = q.front();
    q.pop();

if (curr->left)
{
    /* code */
    parent_track[curr->left] = curr;
    q.push(curr->left);
}

if (curr->right)
{
    parent_track[curr->right] = curr;
    q.push(curr->right);
}




}






}


  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        

Node *tar = findTarget(root , target);
unordered_map<Node* , Node*> parent_track;


markParents(root , parent_track );


unordered_map<Node* , bool> visited;


queue<Node*> q;



q.push(tar);



visited[tar] = true;

int curr_lvl = 0;


while (!q.empty())
{
    int size = q.size();
    
    // if (curr_lvl++ == k)
    // {
        
    //     break;
    // }
    curr_lvl ++;

for (int i = 0; i < size; i++)
{
    
    Node*curr = q.front();
    q.pop();


if (curr->left && !visited[curr->left])
{
    /* code */

q.push(curr->left);
visited[curr->left] = true;

}


if (curr->right && !visited[curr->right])
{
    /* code */

q.push(curr->right);

visited[curr->right] = true;
}

if (parent_track[curr]  && !visited[parent_track[curr]])
{
    /* code */


q.push(parent_track[curr]);
visited[parent_track[curr]] = true;


}




}




}



return curr_lvl;

        
        
    }
};

int main()
{
    IOS;
    

}