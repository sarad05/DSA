//Recursive code
TC: O(2^N) 
class Solution {
 private:
    int helper(int ind,vector<int>&nums)
    {
         if(ind==0)  return nums[ind];
        if(ind<1) return 0;
        int pick= nums[ind] + helper(ind-2,nums);
        int notpick = 0 + helper(ind-1,nums);
        return max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
       return helper(n-1,nums);
    }
};

//Memoization code 

TC: O(N)
Space: O(N) + O(N)
class Solution {
private:
    int helper(int ind,vector<int>&nums,vector<int>& dp)
    {
         if(ind==0)  return nums[ind];
        if(ind<1) return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int pick= nums[ind] + helper(ind-2,nums,dp);
        int notpick = 0 + helper(ind-1,nums,dp);
        return dp[ind] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
       return helper(n-1,nums,dp);
    }
};
    
//Tabulation code

TC: O(N)
Space: O(N) 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
       dp[0]=nums[0];
        int neg=0;
        for(int ind=1;ind<n;ind++)
        {
            int pick = nums[ind] ;
                if(ind>1)
                    pick+= dp[ind-2];
            int notpick = 0 + dp[ind-1];
            dp[ind] = max(pick,notpick);
        }
        return dp[n-1];
    }
};


//Space Optimization code

TC: O(N)
Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int prev,prev2,curri;
        prev=nums[0];
        prev2=0;
        for(int ind=1;ind<n;ind++)
        {
            int pick = nums[ind];
                if(ind>1)
                    pick+= prev2;
            int notpick = 0 + prev;
            curri = max(pick,notpick);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};



