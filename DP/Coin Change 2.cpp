Recursive approach
------------------

class Solution {
    private:
    int find(int ind,vector<int>&coins,int amount)
    {
        if(ind==0) {
            if(amount%coins[ind]==0)   return 1;
            else  return 0;
        } 
        int notTake = find(ind-1,coins,amount);
        int take =0;
        if(coins[ind]<=amount)  
        {
            take = find(ind,coins,amount-coins[ind]);
        }
        return take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return find(n-1,coins,amount);
    }
};



Memoised Approach
-------------------

class Solution {
    private:
    int find(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        if(ind==0) {
            if(amount%coins[ind]==0)   return 1;
            else  return 0;
        } 
        if(dp[ind][amount]!=-1)  return dp[ind][amount];
        int notTake = find(ind-1,coins,amount,dp);
        int take =0;
        if(coins[ind]<=amount)  
        {
            take = find(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount] = take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return find(n-1,coins,amount,dp);
    }
};


Tabulation Approach
--------------------

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                 dp[0][i] = 1;
            }
        }
        for(int ind =1; ind<n; ind++)
        {
            for(int amt = 0 ; amt<=amount;amt++)
            {
                int notTake = dp[ind-1][amt];
                int take = 0;
                if(coins[ind]<=amt)
                {
                    take = dp[ind][amt-coins[ind]];;
                }
                dp[ind][amt] = take + notTake; 
            }
        }
        return dp[n-1][amount];
    }
};

//Space Optimised Approach
------------------------------
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                 prev[i] = 1;
            }
        }
        for(int ind =1; ind<n; ind++)
        {
            for(int amt = 0 ; amt<=amount;amt++)
            {
                int notTake = prev[amt];
                int take = 0;
                if(coins[ind]<=amt)
                {
                    take = curr[amt-coins[ind]];;
                }
                curr[amt]= take + notTake; 
            }
            prev = curr;
        }
        return prev[amount];
    }
};
