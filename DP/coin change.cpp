//Recursive Code
class Solution {
    private:
    int func(int ind,vector<int>&coins,int target)
    {
        if(ind==0)
        {
            if(target%coins[ind]==0)   return target/coins[ind];
            else   return 1e9;
        }
        int notTake = 0 + func(ind-1,coins,target);
        int take = INT_MAX;
        if(coins[ind]<=target)
        {
            take = 1 + func(ind,coins,target-coins[ind]);
        }
        return min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = func(n-1,coins,amount);
        if(ans>=1e9)   return -1;   //as there might be a case when take = 1+1e9 (this take will exceeded)
        return ans;                 //that is infinte no of times taking coins and not able to find the amount
    }                               //due to which returning -1;
};


//Memoisation code

class Solution {
    private:
    int func(int ind,vector<int>&coins,int target,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(target%coins[ind]==0)   return target/coins[ind];
            else   return 1e9;
        }
        if(dp[ind][target]!=-1)  return dp[ind][target];
        int notTake = 0 + func(ind-1,coins,target,dp);
        int take = INT_MAX;
        if(coins[ind]<=target)
        {
            take = 1 + func(ind,coins,target-coins[ind],dp);
        }
        return dp[ind][target] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = func(n-1,coins,amount,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};


//Tabulation code

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        int ans = 0;
        for(int i=0;i<=amount;i++) {
            if(i%coins[0]==0)
            {
               dp[0][i] = i/coins[0];
            }
            else
            {
                dp[0][i] = 1e9;
            }
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                int notTake = 0 + dp[ind-1][amt];
                int take = 1e9;
                if(coins[ind]<=amt)
                {
                    take = 1 + dp[ind][amt-coins[ind]];
                }
                dp[ind][amt] = min(take,notTake);
            }
        }
        ans = dp[n-1][amount];
        if(ans>=1e9)  return -1;
        return ans;
    }
};

//Space Optimised code
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        int ans = 0;
        for(int i=0;i<=amount;i++) {
            if(i%coins[0]==0)
            {
               prev[i] = i/coins[0];
            }
            else
            {
                prev[i] = 1e9;
            }
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                int notTake = 0 + prev[amt];
                int take = 1e9;
                if(coins[ind]<=amt)
                {
                    take = 1 + curr[amt-coins[ind]];
                }
                curr[amt] = min(take,notTake);
            }
            prev = curr;
        }
        ans = prev[amount];
        if(ans>=1e9)  return -1;
        return ans;
    }
};
