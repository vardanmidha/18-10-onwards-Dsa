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

int count(int n){

if (n==0)
{
    
    return 0;
}


return 1 + count(n/10);


}

public:
    int maximum69Number (int num) {



int n = count(num);


while (num>0)
{
    
    
if (num/(pow(10, n-1)) == 6 )
{
    

    
}




}





    }
};


int main()
{
    IOS;
    

}