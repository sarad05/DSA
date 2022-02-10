//Brute force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {  int sum = nums[i];
            for(int j=i+1;j<n;j++)
            {
                 sum +=nums[j];
                if(sum==k)
                {
                    cnt++;
                }
            }
        }
        for(int i=0;i<n;i++)  if(nums[i]==k)  cnt++;
        //if(nums[n-1]==k)  cnt++;
        return cnt;
    }
};

//Optimized solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        mp[0] = 1;
        int sum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
             sum += nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                cnt+=mp[sum-k];
            }
           mp[sum]++;
        }
        return cnt;
    }
};