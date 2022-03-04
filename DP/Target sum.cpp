//This Approach is same as Partitions with given difference

//Tabulation approach
class Solution {
    private:
    int countPartitions(int n, int d, vector<int> &arr) {
    int totsum=0;
    for(auto it:arr)
    {
        totsum+=it;
    }
    if((totsum-d)%2 || totsum-d<0)  return false;
    int tar = (totsum-d)/2;
    vector<vector<int>>  dp(n,vector<int>(tar+1,0));
    if(arr[0]==0)  dp[0][0] = 2;      //ith is ind and jth is sum
    else   dp[0][0] = 1;
    if(arr[0]!=0 && arr[0]<=tar)  dp[0][arr[0]] = 1;
    for(int ind=1;ind<n;ind++)
    {
        for(int sum = 0;sum<=tar;sum++)
        {
            int nottake = dp[ind-1][sum];
            int take = 0;
            if(arr[ind]<=sum)
            {
                take = dp[ind-1][sum-arr[ind]];
            }
            dp[ind][sum] = (take+nottake);
        }
    }
    return dp[n-1][tar];
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};