/*
This problem is a little tricky at first glance. However, if you have solved the House Robber problem, this problem can simply be decomposed into two House Robber problems.
Suppose there are n houses, since house 0 and n - 1 are now neighbours, we cannot rob them together and thus the solution is now the maximum of

Rob houses 0 to n - 2;
Rob houses 1 to n - 1.
*/
class Solution {
    private:
        int solve(vector<int>&nums)
        {int n=nums.size();
            vector<int> dp(n);
            dp[0]=nums[0];
            for(int i=1;i<n;i++)
            {
               int pick =nums[i];
                if(i>1)
                    pick+=dp[i-2];
               int notpick=0 + dp[i-1];
                dp[i]=max(notpick,pick);
            }
         return dp[n-1];
        } 
public:
    int rob(vector<int>& nums)
    {
          int size=nums.size();
        int max_ans=0;
        vector<int> temp1(nums.begin(),nums.end()-1);
        vector<int> temp2(nums.begin()+1,nums.end());
        if(size==0)
        {
            return 0;
        }
        else if(size==1)
        {
            return nums[0];
        }
        else
        {
            max_ans=max(solve(temp1),solve(temp2));
        }
        return max_ans;
    }
};