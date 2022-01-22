//Recursive code

class Solution {
    private:
    int findpath(int i,int j, vector<vector<int>>&grid)
    {
      if(i==0 && j==0)
      {
          return grid[i][j];
      }
        if(i<0 ||j<0)  return 1e9;
        int up = grid[i][j] + findpath(i-1,j,grid);
        int left = grid[i][j] + findpath(i,j-1,grid);
        return min(left,up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return findpath(n-1,m-1,grid); 
    }
};



//Memoization
class Solution {
    private:
    int findpath(int i,int j, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
      if(i==0 && j==0)
      {
          return grid[i][j];
      }
        if(i<0 ||j<0)  return 1e9;
        if(dp[i][j]!=-1)  return dp[i][j];
        int up = grid[i][j] + findpath(i-1,j,grid, dp);
        int left = grid[i][j] + findpath(i,j-1,grid, dp);
        return dp[i][j] = min(left,up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return findpath(n-1,m-1,grid,dp); 
    }
};


//Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int up,left;
        vector<vector<int>> dp(n,vector<int>(m,-1));
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { if(i==0 && j==0)    dp[i][j] = grid[i][j];
             else
             {
                  up = grid[i][j];
                    if(i>0) up+= dp[i-1][j];
                   else   up+=1e9;
                    left = grid[i][j];
                      if(j>0) left+=dp[i][j-1];
                else  left+=1e9;
                dp[i][j] = min(up,left);
             }
            }
        }
        return dp[n-1][m-1];
    }
};

//Space Optimised solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int up,left;
        vector<vector<int>> dp(n,vector<int>(m,-1));
       vector<int> prev(m,0);
        for(int i=0;i<n;i++)
        {     vector<int> curr(m,0);
            for(int j=0;j<m;j++)
            { if(i==0 && j==0)    curr[j] = grid[i][j];
             else
             {
                  up = grid[i][j];
                 
                 //prev row j column
                    if(i>0) up+= prev[j];   
                   else   up+=1e9;
                    left = grid[i][j];
                 
                 //current's row j-1 column
                      if(j>0) left+=curr[j-1];
                else  left+=1e9;
               curr[j] = min(up,left);
             }
            }
         prev=curr;
        }
        return prev[m-1];   //loop ends in m so its prev is prev[m-1]
    }
};


//Another way of doing tabulation
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int dp[n][m];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1) //handling last cell of the grid
            {
                dp[i][j] = grid[i][j];
            }
            else if (i == n - 1) //for last column of the grid
            {
                dp[i][j] = dp[i][j + 1] + grid[i][j];
            }
            else if (j == m - 1) //handling last row of the grid
            {
                dp[i][j] = dp[i + 1][j] + grid[i][j];
            }
            else //handling rest of the grid
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
    }
    cout << dp[0][0];
    return 0;
}