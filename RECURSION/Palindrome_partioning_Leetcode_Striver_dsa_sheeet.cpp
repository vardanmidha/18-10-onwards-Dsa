#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


class Solution
{

public:

bool ispalindrome(int start , int end , string s){


while (start<=end)
{
    if (s[start++] !=s[end--])
    {
        return false;
    }
    
    return true;
}




}

public:



void solve(int ind , string s , vector<string> &path , vector<vector<string>> &ans)
{


if (ind>=s.size())
{

    ans.push_back(path);
    return ;
}

for (int i = ind; i < s.size(); i++)
{
    

if (ispalindrome(ind , i , s))
{
    
    path.push_back(s.substr(ind , i-ind+1));
    solve(i+1, s , path , ans);  

path.pop_back();

}


    
}








}



public:
    vector<vector<string>> partition(string s)
    {

//         vector<vector<string>> basically means 3-d array
        vector<vector<string>> ans;

    
        vector<string> path;
    
        solve(0 , s , path , ans);
        
    return ans;
    }
};

int main()
{
    IOS;
    



}