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
    bool check(vector<int>& nums) {


int count =0;



for (int i = 0; i < nums.size(); i++)
{
    
    if (nums[i] > nums[(i+1)%nums.size()])
    {
        count ++ ;
    }
    
    

}

return count<=1;


    }
};


int main()
{
    IOS;
    

}