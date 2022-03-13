//Recursive Approach

int f(int i,int j,int limit,int k,vector<vector<int>>& grid)
{
    //base case
    if(i<0 || j<0)  return INT_MIN;
    if(i==0 && j==0)
    {
        if(limit>0)   return grid[0][0];
        return 0;
    }
    int ans = INT_MIN;
    //if i can take the given grid
    if(limit > 0)
    {
       ans = max(ans,grid[i][j] + f(i-1,j,k,k,grid));   //moving up
       ans = max(ans,grid[i][j] + f(i,j-1,limit - 1,k,grid));   //moving left;
    }   
    //else i am not taking it
    ans = max(ans,f(i-1,j,k,k,grid));
    ans = max(ans,f(i,j-1,limit,k,grid));
    return ans;
}
int maximumCoins(int n, int m, int k, vector<vector<int>> &grid){
    // Write your code here.
    return f(n-1,m-1,k,k,grid);
}


//Memoization
----------------

#include<bits/stdc++.h>
int f(int i,int j,int limit,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
{                                                      
    //base case
    if(i<0 || j<0)  return INT_MIN;
    if(i==0 && j==0)
    {
        if(limit>0)   return grid[0][0];
        return 0;
    }
    if(dp[i][j][limit]!=-1)   return dp[i][j][limit];
    int ans = INT_MIN;
    //if i can take the given grid
    if(limit > 0)
    {
       ans = max(ans,grid[i][j] + f(i-1,j,k,k,grid,dp));   //moving up
       ans = max(ans,grid[i][j] + f(i,j-1,limit - 1,k,grid,dp));   //moving left;
    }   
    //else i am not taking it
    ans = max(ans,f(i-1,j,k,k,grid,dp));
    ans = max(ans,f(i,j-1,limit,k,grid,dp));
    return dp[i][j][limit] = ans;
}
int maximumCoins(int n, int m, int k, vector<vector<int>> &grid){
    // Write your code here.
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
    return f(n-1,m-1,k,k,grid,dp);
}


//Tabulation
------------------

int maximumCoins(int n, int m, int k, vector<vector<int>> &grid){
    // Write your code here.
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,0)));
    for(int limit=1;limit<=k;limit++)
    {
      dp[0][0][limit] = grid[0][0];
    }
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            for(int limit = 1;limit<=k;limit++)
            {
                if(i==0 && j==0)  continue;
                 int ans = INT_MIN;
            //if i can take the given grid
            if(limit > 0)
            {
              if(i-1>=0) ans = max(ans,grid[i][j] + dp[i-1][j][k]);   //moving up
              if(j-1>=0) ans = max(ans,grid[i][j] + dp[i][j-1][limit - 1]);   //moving left;
            }   
            //else i am not taking it
           if(i-1>=0) ans = max(ans,dp[i-1][j][k]);
            if(j-1>=0) ans = max(ans,dp[i][j-1][limit]);
            dp[i][j][limit] = ans;
           }
        }
    }
    return dp[n-1][m-1][k];
}
