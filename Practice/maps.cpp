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
    


map<int ,map<int, vector<int>>> mpp;

mpp[5][0] = {1,2,3,4};
mpp[1][8] = {5,6,7,8};
mpp[2][0] ={0,9,5};



for(auto i:mpp){

for(auto j:i.second){

for( auto k : j.second ){

cout<<k<<" ";
}

}

}



}