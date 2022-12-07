#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


class Solution {


public:


void solve(int ind , string s , vector<string> &ans , string out ){


if (ind>=s.size())
{
    ans.push_back(s);
    return ;
}


solve(ind+1 , s , ans , out);
out.push_back(s[ind]);
solve(ind+1 ,s ,  ans ,out );


}



public:
    int numTilePossibilities(string s) {
     

vector<string> ans;

int count = 0;
string out;
solve(0  , s , ans , out);



map<string , int> mpp;

for (int i = 0; i < ans.size(); i++)
{
    mpp[ans[i]]++;
}

        
        count = mpp.size();
        
       
            
            




return count;
  
  
        // return 0;
    }
};


int main()
{
    IOS;
    



}