#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

int main()
{
    IOS;
    

map<int , int> mpp;

// mpp.insert({1,2});
mpp[1] = 5;

// cout<<mpp.first<<mpp.second;
for(auto it: mpp){

cout<<it.first<<it.second;

}



}