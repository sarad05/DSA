#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        int end=n-1;
        int ans=-1;
        if(n==1)
            return 0; 
        while(start<end)
        {
            int mid=start+(end-start)/2;
         if(nums[mid]>nums[mid+1])
         {
             ans=mid;
             end=mid;
         }
        else
        {
            ans=mid+1;
            start=mid+1;
        }
        }
        return ans;
    }
int main()
{
    vector<int> nums={1,2,1,3,5,6,4};
    cout<<findPeakElement(nums);
return 0;
}    