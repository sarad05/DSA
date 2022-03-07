//Recursive Code
------------------

int func(int indx,int w,vector<int>&profit,vector<int>&weight)
{
    if(indx==0)
    {
        if(weight[indx]<=w)
        {
            return int(w/weight[0])*profit[indx];
        }
        else
        {
            return 0;
        }
    }
    int notTake = 0 + func(indx-1,w,profit,weight);
    int take = 0;
    if(weight[indx]<=w)
    {
        take = profit[indx] + func(indx,w-weight[indx],profit,weight);
    }
    return max(take,notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return func(n-1,w,profit,weight);
}


//Memoized code
--------------------

int func(int indx,int w,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp)
{
    if(indx==0)
    {
        if(weight[indx]<=w)
        {
            return int(w/weight[0])*profit[indx];
        }
        else
        {
            return 0;
        }
    }
    if(dp[indx][w]!=-1)   return dp[indx][w];
    int notTake = 0 + func(indx-1,w,profit,weight,dp);
    int take = 0;
    if(weight[indx]<=w)
    {
        take = profit[indx] + func(indx,w-weight[indx],profit,weight,dp);
    }
    return dp[indx][w] = max(take,notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return func(n-1,w,profit,weight,dp);
}

//Tabulation code
------------------

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i=weight[0];i<=w;i++)
    {
        dp[0][i] = (int(i/weight[0]))*profit[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int wt = 0; wt<=w;wt++)
        {
            int notTake = 0 + dp[i-1][wt];
            int take = 0;
            if(weight[i]<=wt)
            {
                take = profit[i] + dp[i][wt-weight[i]];
            }
            dp[i][wt] = max(take,notTake);
        }
    }
    return dp[n-1][w];
}

//Space Optimized code
------------------------

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int>prev(w+1,0),curr(w+1,0);
    for(int i=weight[0];i<=w;i++)
    {
        prev[i] = (int(i/weight[0]))*profit[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int wt = 0; wt<=w;wt++)
        {
            int notTake = 0 + prev[wt];
            int take = 0;
            if(weight[i]<=wt)
            {
                take = profit[i] + curr[wt-weight[i]];
            }
            curr[wt] = max(take,notTake);
        }
        prev = curr;
    }
    return prev[w];
}


-------------------------------------------------------------------------
//old implementation

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
    vector<int> dp(cap+1);
    dp[0]=0;
    for(int bagc=1;bagc<=cap;bagc++)    //bagc=bag capacity
    { int max=0;
         for(int i=0;i<n;i++)
       {
        if(wt[i]<=bagc)
        {
            int rbagc=bagc-wt[i];     //rbagc=remaining bag capacity
            int rbagv=dp[rbagc];      //rbagv=remaining bag value
            int tbagv=rbagv+val[i];   //tbagv=total bag value
            if(tbagv>max)
            {
                max=tbagv;
            }
        }
      }
      dp[bagc]=max; 
    }
    cout<<dp[cap];
    return 0;
}