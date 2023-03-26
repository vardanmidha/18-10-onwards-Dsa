#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


class Solution {


int solve(int i , int j ,vector<vector<int>>& matrix , int m , int n , vector<vector<int>> &dp){


if (i==m-1)
{
    return dp[i][j] = matrix[i][j];
}

if (dp[i][j] !=-1)
{
    return dp[i][j];
}

int down = INT_MAX , ldg = INT_MAX , rdg = INT_MAX;

if (i+1< m)
{
    down = matrix[i][j] + solve(i+1 , j , matrix , m , n , dp);
}

if (i+1 <m && j-1 >=0)
{
    ldg = matrix[i][j] + solve(i+1 , j-1 , matrix , m , n , dp);
}

if (i+1 <m && j+1 <n)
{
    rdg = matrix[i][j] + solve(i+1 , j+1 , matrix , m , n , dp);
}


return dp[i][j]  = min(down , min(ldg , rdg));



}



public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

int m = matrix.size();
int n = matrix[0].size();

vector<vector<int>> dp(m , vector<int>(n ,-1));

int mini = INT_MAX;

for (int i = 0; i < n; i++)
{
    
    int ans = solve(0 , i , matrix ,m , n , dp);

mini =  min(mini , ans);

}

return mini;

    }
};


int main()
{
    IOS;
    

}