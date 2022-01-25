LEETCODE 120 : (Triangle) 

//Recursive approach
class Solution {
    int helper(int i,int j,int row,int col,vector<vector<int>>& triangle)
    {
        if(i==row-1)
        {
            return triangle[row-1][j];
        }
        int down = triangle[i][j] + helper(i+1,j,row,col,triangle);
        int diag = triangle[i][j] + helper(i+1,j+1,row,col,triangle);
        return min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        return helper(0,0,row,col,triangle);
    }
};


//Memoization approach

class Solution {
    int helper(int i,int j,int row,int col,vector<vector<int>>& triangle, vector<vector<int>> &dp)
    {
        if(i==row-1)
        {
            return triangle[row-1][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down = triangle[i][j] + helper(i+1,j,row,col,triangle,dp);
        int diag = triangle[i][j] + helper(i+1,j+1,row,col,triangle,dp);
        return dp[i][j] = min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        vector<vector<int>> dp(row,vector<int>(row,-1));
        return helper(0,0,row,col,triangle,dp);
    }
};

//Tabulation approach
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        vector<vector<int>> dp(row,vector<int>(row,0));
         for(int j=0; j<row ;j++)
       {
           dp[row-1][j] = triangle[row-1][j];
       }
        for(int i=row-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
               int down = triangle[i][j] + dp[i+1][j];
               int diagonal = triangle[i][j] + dp[i+1][j+1];
               dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};

//space optimization 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        vector<int> front(row);
         for(int j=0; j<row ;j++)
       {
           front[j] = triangle[row-1][j];
       }
        for(int i=row-2;i>=0;i--)
        {    vector<int> curr(row);
            for(int j=i;j>=0;j--)
            {
               int down = triangle[i][j] + front[j];
               int diagonal = triangle[i][j] + front[j+1];
               curr[j] = min(down,diagonal);
            }
         front = curr;
        }
        return front[0];
    }
};