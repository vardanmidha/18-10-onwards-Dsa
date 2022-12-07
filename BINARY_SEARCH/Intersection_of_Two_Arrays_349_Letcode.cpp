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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {



int start = 0;
int end = nums2.size()-1;

vector<int> ans;



for (int i = 0; i < nums1.size(); i++)
{
    
    int out = nums1[i];

int mid = start + (end-start)/2;

if (nums1[mid] == out)
{
    ans.push_back(out);
    ans.push_back(nums[mid]);

}



}





    }
};

int main()
{
    IOS;
    

}