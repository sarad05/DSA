//Recursive Approach

class Solution {
    private:
    int f(int ind,vector<int>&prices,int size,int buy,int cap)
    {   if(cap==0)   return 0;
        if(ind==size) return 0;
       long profit = 0;
     if(buy)
     {
         profit =  max(-prices[ind]+f(ind+1,prices,size,0,cap),0 + f(ind+1,prices,size,1,cap));
     }
     else
     {
         profit = max(prices[ind] + f(ind+1,prices,size,1,cap-1), 0 + f(ind+1,prices,size,0,cap));
     }
     return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        return f(0,prices,n,buy,2);
    }
};



//Memoization

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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,prices,n,buy,2,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
      
        for(int ind = 0;ind<=n;ind++)
       {
           for(int buy=0;buy<2;buy++)
           {
               dp[ind][buy][0] = 0;
           }
       }
        for(int buy= 0;buy<2;buy++)
        {
            for(int cap=0;cap<3;cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0; buy<2;buy++)
            {
                for(int cap = 1;cap<3;cap++)
                {
                     long profit = 0;
                     if(buy)
                     {
                         profit = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                     }
                    else
                    {
                        profit = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};

//space Optimization Approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<int>> ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        for(int ind = 0;ind<=n;ind++)
       {
           for(int buy=0;buy<2;buy++)
           {
               curr[buy][0] = 0;
           }
       }
        for(int buy= 0;buy<2;buy++)
        {
            for(int cap=0;cap<3;cap++)
            {
                ahead[buy][cap] = 0;
            }
        }
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0; buy<2;buy++)
            {
                for(int cap = 1;cap<3;cap++)
                {
                     long profit = 0;
                     if(buy)
                     {
                         profit = max(-prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                     }
                    else
                    {
                        profit = max(prices[ind] + ahead[1][cap-1], 0 + ahead[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
                ahead = curr;
            }
        }
        return ahead[1][2];
    }
};