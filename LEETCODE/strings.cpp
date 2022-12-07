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
    


string s = "hello";

s.erase(s.size()-1 , 1);
s.erase(0,1);

s.erase(2,1);
cout<<s;

}