#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long> 
#define v1 vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


 int distinctAverages(vector<int>& nums) {




int n = nums.size();

sort(nums.begin() , nums.end());

unordered_map<int , int > mpp;


while (!nums.empty())
{
    
int mini = nums[0];
    int maxi = nums[nums.size()-1];

int sum = (mini+maxi)/2;
cout<<sum<<" ";
mpp[sum]++;

nums.pop_back();
nums.erase(nums.begin());

}



return mpp.size();


    }

int main()
{
    IOS;


    vector<int> nums = {0,2,5,7,7,7,8,8,9,9};
    // vector<int> nums = 
    
int ans = distinctAverages(nums);

cout<<ans;

}