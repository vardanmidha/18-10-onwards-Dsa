#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


void helper(int *arr , int n){

int ans =0;
int maxi =0;

 int zcnt =0;
 int ocnt =0;
 int cnt =0;

 for (int i = 0; i < n; i++)
 {


    
    if (arr[i] ==0)
    {
        zcnt ++;
    }
    
    if (arr[i]==1)
    {
        ocnt ++;
    }
    


for (int j = 0; j < n; j++)
{
    
    if (arr[i] == arr[j] && i!=j)
    {
        cnt ++;
        
    }
    
}

maxi = max(maxi , cnt);

 }
 


if (zcnt >= maxi && zcnt>ocnt)
{
    
    cout<< n - zcnt - ocnt;

cout<<endl;
}

else if (ocnt >= maxi && ocnt>=zcnt)
{
    cout<< n - ocnt - zcnt;
    cout<<endl;
}

 else
 {
    cout<<n-zcnt-ocnt-maxi;
    cout<<endl;
 }
 







}


int main()
{
    IOS;
    

int t;
cin>>t;
while (t--)
{
    
    int n;
    cin>>n;

    int arr[100000];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    

helper(arr , n );

}




}