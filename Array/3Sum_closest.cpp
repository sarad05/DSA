/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
#include<bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
        pair<int,int> ans={INT_MAX,INT_MAX};
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {  int start=i+1,end=nums.size()-1;
            while(start<end)
          {
          
            int cursum=nums[i]+nums[start]+nums[end];
            if(abs(cursum-target)<ans.first)
            {
                ans.first=abs(cursum-target);       
                ans.second=nums[i]+nums[start]+nums[end];    
            }
            if(cursum<=target)
            {
                start++;
            }
            else{
              end--;
            }
            }
        }
        return ans.second;
}
int main()
{
vector<int> nums={-1,2,1,-4};
int target=1;
int ans=threeSumClosest(nums,target);
cout<<ans;
return 0;
}