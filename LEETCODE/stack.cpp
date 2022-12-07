#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
#include<stack>
using namespace std ;

int main()
{
    IOS;
    


stack<char> st;


string ans = "abcd";

st.push(ans[0]);

st.push(ans[1]);

st.push(ans[2]);

st.push(ans[3]);




string out;
int j=0;
while (!st.empty())
{
  out.push_back(st.top());
    st.pop();
 j++;

}



cout<<out;


}