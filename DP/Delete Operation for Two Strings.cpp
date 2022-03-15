//Recursion Approach

class Solution {
    int f(int i,int j,string s1,string s2)
    {
        if(i<0)  return j+1;
        if(j<0)  return i+1;
        if(s1[i]==s2[j])
        {
            return 0 + f(i-1,j-1,s1,s2);
        }
        return 1 + min(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return f(n-1,m-1,word1,word2);
    }
};


//Memoization Approach

class Solution {
    int f(int i,int j,string s1,string s2,vector<vector<int>> &dp)
    {
        if(i<0)  return j+1;
        if(j<0)  return i+1;
        if(dp[i][j]!=-1)   return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j] = 0 + f(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j] = 1 + min(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};



//Tabulation

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j] = j;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

//Space Optimization
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++)
        {
            prev[j] = j;
        }
        for(int i=1; i<=n; i++)
        {   curr[0] = i;
            for(int j=1; j<=m; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    curr[j] = 0 + prev[j-1];
                }
                else
                {
                    curr[j] = 1 + min(prev[j],curr[j-1]);
                }
            }
         prev = curr;
        }
        return prev[m];
    }
};
