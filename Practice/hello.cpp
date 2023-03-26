#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;



    BinaryTreeNode* remove(BinaryTreeNode* root, int data) {
        

if(root==NULL){
    return root;
}
// If its a leaf node , no children
if(!root->left && !root->right && root->data == data){
    return NULL;
}

if(root->data == data){

// 1 child and 2 child



//  If only 1 child

if(!root->left || !root->right){


if(root->left){
    return root->left;
    }
else {
    return root->right;
}

}

// If Node has 2 children

else{


// BinaryTreeNode *temp = root->right;
// BinaryTreeNode *lft = root->left;

// while(temp->left){

// temp = temp->left;

// }

// root->data = temp->data;
// root->right = remove(root->right , temp->data);
 

 BinaryTreeNode *temp = root->left;
 BinaryTreeNode *rgt = root->right;

 while(temp->right){
     temp = temp->right;
 }
root->data = temp->data;

root->left = remove(root->left , temp->data);

}



}



if(root->data > data){
    root->left = remove(root->left , data);
}
else{
    root->right = remove(root->right , data);
}


return root;
    }


int main()
{
    IOS;
    


}