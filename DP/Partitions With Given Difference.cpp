//Recursive approach

int mod = (int)(1e9+7);
int findans(int ind,int sum,vector<int>&arr)
{
    if(ind==0)
    {
        if(sum==0 && arr[0]==0)  return 2;
        if(sum==0 || sum==arr[0])   return 1;
        return 0;
    }
    int notpick = findans(ind-1,sum,arr);
    int pick = 0;
    if(arr[ind]<=sum)
    {
        pick = findans(ind-1,sum-arr[ind],arr);
    }
    return pick+notpick;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totsum=0;
    for(auto it:arr)
    {
        totsum+=it;
    }
   // cout<<totsum<<endl;
    if((totsum-d)%2 || totsum-d<0)  return false;
    return findans(n-1,(totsum-d)/2,arr);
}

//memoization

int findans(int ind,int sum,vector<int>&arr,vector<vector<int>> &dp)
{
    if(ind==0)
    {
        if(sum==0 && arr[0]==0)  return 2;
        if(sum==0 || sum==arr[0])   return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1)  return dp[ind][sum]; 
    int notpick = findans(ind-1,sum,arr,dp);
    int pick = 0;
    if(arr[ind]<=sum)
    {
        pick = findans(ind-1,sum-arr[ind],arr,dp);
    }
    return dp[ind][sum]=(pick+notpick)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totsum=0;
    
    for(auto it:arr)
    {
        totsum+=it;
    }
   // cout<<totsum<<endl;
    
    if((totsum-d)%2 || totsum-d<0)  return false;
    int tar = (totsum-d)/2;
    vector<vector<int>>  dp(n,vector<int>(tar+1,-1));
    return findans(n-1,(totsum-d)/2,arr,dp);
}

//Tabulation approach

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
            dp[ind][sum] = (take+nottake)%mod;
        }
    }
    return dp[n-1][tar];
}

//Space Optimized approach
int mod = (int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    int totsum=0;
    for(auto it:arr)
    {
        totsum+=it;
    }
    if((totsum-d)%2 || totsum-d<0)  return false;
    int tar = (totsum-d)/2;
    vector<int> prev(tar+1,0),curr(tar+1,0);
    if(arr[0]==0)  prev[0] = 2;      //ith is ind and jth is sum
    else   prev[0] = 1;
    if(arr[0]!=0 && arr[0]<=tar)  prev[arr[0]] = 1;
    for(int ind=1;ind<n;ind++)
    {
        for(int sum = 0;sum<=tar;sum++)
        {
            int nottake = prev[sum];
            int take = 0;
            if(arr[ind]<=sum)
            {
                take = prev[sum-arr[ind]];
            }
            curr[sum] = (take+nottake)%mod;
        }
        prev=curr;
    }
    return prev[tar];
}


