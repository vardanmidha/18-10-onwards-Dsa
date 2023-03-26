#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;



bool Tabulation(int ind , vector<int> &arr , int k , vector<vector<int>> &dp){





    
}


bool Memoization(int ind ,  vector<int> &arr , int k , vector<vector<int>> &dp){


if (ind==0)
{
    // return arr[0] == k;

if (arr[0] ==k)
{
    return dp[ind][k] = true;
}
return dp[ind][k] = false;

}
if (k==0)
{
    return dp[ind][k] =true;
}


if (dp[ind][k] !=-1)
{
    return dp[ind][k];
}

 bool notPick = Memoization(ind-1 , arr , k , dp);
bool pick = false;
if (k>= arr[ind])
{

pick = Memoization(ind-1 , arr , k-arr[ind] , dp);    
    
}

return dp[ind][k] = pick || notPick;


}



bool solve(int ind , int k  ,vector<int> &arr){


if (ind==0)
{
    return arr[0] == k;
}


bool notPick = solve(ind-1 , k , arr);

bool pick = false;

if (k>=arr[ind])
{
    
pick = solve(ind-1 , k-arr[ind]  , arr);

}



return pick || notPick;


}

bool subsetSumToK(int n, int k, vector<int> &arr) {


vector<vector<int>> dp(n+1 , vector<int>(k+1 , -1));


return Memoization(n-1 , arr , k , dp);


}



int main()
{
    IOS;
    

}