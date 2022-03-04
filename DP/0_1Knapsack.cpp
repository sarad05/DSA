//Recursive Approach
int findans(int ind,vector<int>&weight,vector<int>&val,int W)
{
    if(ind==0)
    {
        if(weight[ind]<=W)
        {
            return val[ind];
        }
        else
        {
            return 0;
        }
    }
    int notTake = findans(ind-1,weight,val,W);
    int take = 0;
    if(weight[ind]<=W)
    {
        take = val[ind] + findans(ind-1,weight,val,W-weight[ind]);
    }
    return max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
	return findans(n-1,weight,value,maxWeight);
}

//Memoization approach

int findans(int ind,vector<int>&weight,vector<int>&val,int W,vector<vector<int>> &dp)
{
    if(ind==0)
    {
        if(weight[ind]<=W)
        {
            return val[ind];
        }
        else
        {
            return 0;
        }
    }
    if(dp[ind][W]!=-1)   return dp[ind][W];
    int notTake = findans(ind-1,weight,val,W,dp);
    int take = 0;
    if(weight[ind]<=W)
    {
        take = val[ind] + findans(ind-1,weight,val,W-weight[ind],dp);
    }
    return dp[ind][W] = max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return findans(n-1,weight,value,maxWeight,dp);
}


//Tabulation approach

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int W=weight[0];W<=maxWeight;W++)   dp[0][W] = value[0];
    for(int ind = 1;ind<n;ind++)
    {
        for(int W=0;W<=maxWeight;W++)
        {
            int notTake =0 + dp[ind-1][W];
            int take = INT_MIN;
             if(weight[ind]<=W)
             {
               take = value[ind] + dp[ind-1][W-weight[ind]];
             }
             dp[ind][W] = max(take,notTake);
        }
    }
	return dp[n-1][maxWeight];
}

//Space Optimized Approach

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   vector<int> prev(maxWeight+1),curr(maxWeight+1);
    for(int W=weight[0];W<=maxWeight;W++)   prev[W] = value[0];
    for(int ind = 1;ind<n;ind++)
    {
        for(int W=0;W<=maxWeight;W++)
        {
            int notTake =0 + prev[W];
            int take = INT_MIN;
             if(weight[ind]<=W)
             {
               take = value[ind] + prev[W-weight[ind]];
             }
             curr[W] = max(take,notTake);
        }
        prev=curr;
    }
	return prev[maxWeight];
}

//Older version
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int cap;
    cin>>cap;
    vector<vector<int>> dp(n+1,vector<int> (cap+1));
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            if(j>=wt[i-1])
            {
                if(dp[i-1][j-wt[i-1]]+val[i-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i-1][j-wt[i-1]]+val[i-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][cap];
    return 0;
}