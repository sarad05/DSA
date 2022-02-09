//Recursive Approach
TC : (2^n) space :Auxiliary stack space
class solution{
    private:
        int findcnt(int ind,vector<int>&num,int k)
            {   if(k==0)   return 1; 
                if(ind==0)
                {
                    return (num[0]==k);
                }
            int notpick = findcnt(ind-1,num,k);
            int pick = 0;
            if(num[ind]<=k)
            {
                    pick = findcnt(ind-1,num, k - num[ind]);
            }
            return pick + notpick;
            }
    public:
        int findWays(vector<int> &num, int tar)
        {      
            int n = num.size();
            return findcnt(n-1,num,tar);
           
        }
};

//Memoization Method
TC: O(N*sum)
Space: O(N*sum) + O(N)
class solution{
    private:
        int findcnt(int ind,vector<int>&num,int k,vector<vector<int>>&dp)
            {   if(k==0)   return 1; 
                if(ind==0)
                {
                    return (num[0]==k);
                }
            if(dp[ind][k]!=-1) return dp[ind][k];
            int notpick = findcnt(ind-1,num,k,dp);
            int pick = 0;
            if(num[ind]<=k)
            {
                    pick = findcnt(ind-1,num, k - num[ind],dp);
            }
            return  dp[ind][k] = pick + notpick;
            }
    public:
        int findWays(vector<int> &num, int tar)
        {      
            int n = num.size();
            vector<vector<int>> dp(n,vector<int>(tar+1,-1));
                return findcnt(n-1,num,tar,dp);
           
        }
};

//Tabulation Method
TC: O(N*sum)
Space: O(N*sum)

class solution{
    public:
        int findWays(vector<int> &num, int tar)
        {      
            int n = num.size();
            vector<vector<int>> dp(n,vector<int>(tar+1,0));
            for(int i=0;i<n;i++)
            {
                dp[i][0] = 1;
            }
            if(num[0]<=tar)  dp[0][num[0]] = 1;
            for(int ind = 1; ind<n ; ind++)
            {
                for(int sum = 0;sum<=tar;sum++)
                {
                    int notpick = dp[ind-1][sum];
                    int pick = 0;
                   if(num[ind]<=sum) pick = dp[ind-1][sum - num[ind]];
                   dp[ind][sum] = pick + notpick;
                }
            }
         return dp[n-1][tar]; 
        }
};

// Space Optimization Method
TC: O(N*sum)
Space: O(sum)
class solution{
    public:
        int findWays(vector<int> &num, int tar)
        {      
            int n = num.size();
            vector<int> prev(tar+1,0),curr(tar+1,0);
             prev[0] = 1 ,curr[0] = 1;
            if(num[0]<=tar)  prev[num[0]] = 1;
            for(int ind = 1; ind<n ; ind++)
            {
                for(int sum = 0;sum<=tar;sum++)
                {
                    int notpick = prev[sum];
                    int pick = 0;
                   if(num[ind]<=sum) pick = prev[sum - num[ind]];
                   curr[sum] = pick + notpick;
                }
                prev = curr;
            }
         return prev[tar]; 
        }
};


