Method 1 : Using Map
 int singleNonDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto it:mp)
        {
           if(it.second==1)
           {
               ans=it.first;
           }
        }
        return ans;
    }


Method 2: Using Bit manipulation method
TC: O(N) Space:O(1)
int singleNonDuplicate(vector<int>& nums) {
       int res=nums[0];
        for(int i=1;i<nums.size();i++)
       {
           res=res^nums[i];
       }
        return res;
    }

Method 3: Using Binary Search
class Solution {
public:
    //Most Optimal TC:O(LogN) Space: O(1)
    int singleNonDuplicate(vector<int>& nums) {
    int low=0,high=nums.size()-2;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==nums[mid^1])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return nums[low];
    }
};