class Solution {
     private:
    int f(int ind,vector<int>&prices,int size,int buy,int cap,vector<vector<vector<int>>>&dp)
    {   if(cap==0)   return 0;
        if(ind==size) return 0;
       long profit = 0;
     if(dp[ind][buy][cap]!=-1)   return dp[ind][buy][cap];
     if(buy)
     {
         profit =  max(-prices[ind]+f(ind+1,prices,size,0,cap,dp),0 + f(ind+1,prices,size,1,cap,dp));
     }
     else
     {
         profit = max(prices[ind] + f(ind+1,prices,size,1,cap-1,dp), 0 + f(ind+1,prices,size,0,cap,dp));
     }
     return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
        int buy = 1;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,prices,n,buy,k,dp);
    }
};