//Recursive solution

class Solution {
    private:
    int getProfit(int ind,vector<int>&prices,int buy,int &n)
    {
        if(ind==n)return 0;
        long profit = 0;
        if(buy)
        {
            profit = max(-prices[ind]+getProfit(ind+1,prices,0,n), 0 + getProfit(ind+1,prices,1,n));
        }
        else
        {
            profit = max(prices[ind]+getProfit(ind+1,prices,1,n),0 + getProfit(ind+1,prices,0,n));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        int buy = 1;
        return getProfit(0,prices,buy,n);
    }
};


//Memoization

class Solution {
    private:
    int getProfit(int ind,vector<int>&prices,int buy,int &n,vector<vector<int>>&dp)
    {
        if(ind==n)return 0;
        long profit = 0;
        if(dp[ind][buy]!=-1)  return dp[ind][buy];
        if(buy)
        {
            profit = max(-prices[ind]+getProfit(ind+1,prices,0,n,dp), 0 + getProfit(ind+1,prices,1,n,dp));
        }
        else
        {
            profit = max(prices[ind]+getProfit(ind+1,prices,1,n,dp),0 + getProfit(ind+1,prices,0,n,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return getProfit(0,prices,buy,n,dp);
    }
};


//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=0;i<2;i++)
        {
            dp[n][i] = 0;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int buy = 0;buy<2;buy++)
            {
                long profit = 0;
                if(buy)
                {
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                 dp[i][buy] = profit;
               
            }
            
        }
        return dp[0][1];
    }
};

//space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        int buy = 1;
        vector<int>ahead(2,0),curr(2,0);
        for(int i=0;i<2;i++)
        {
            ahead[i] = 0;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int buy = 0;buy<2;buy++)
            {
                long profit = 0;
                if(buy)
                {
                    profit = max(-prices[i]+ahead[0],ahead[1]);
                }
                else
                {
                    profit = max(prices[i]+ahead[1],ahead[0]);
                }
                 curr[buy] = profit;   
            }
            ahead = curr;
        }
        return ahead[1];
    }
};