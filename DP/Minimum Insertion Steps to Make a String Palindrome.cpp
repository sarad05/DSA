//Space Optimization Method

class Solution {
    private:
    int f(string &s,string &t)
    {   int n = s.size();
        int m = t.size();
        vector<int> prev(m+1,0),curr(m+1,0);
     for(int i = 1;i<=n;i++)
     {
         for(int j =1;j<=m;j++)
         {
             if(s[i-1]==t[j-1])
             {
                 curr[j] = 1 + prev[j-1];
             }
             else
             {
                 curr[j] = 0 + max(prev[j],curr[j-1]);
             }
         }
         prev = curr;
     }
     return prev[m];
    }
    int LongestPalindromicSubs(string &s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        return f(s,t);
    }
public:
    int minInsertions(string s) {
        int ans = LongestPalindromicSubs(s);
        int size = s.size();
        return size-ans;
    }
};

Tabulation Method
----------------------

class Solution {
    private:
    int f(string &s,string &t)
    {   int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
     for(int i=0;i<=n;i++)
     {
         dp[i][0] = 0;
     }
     for(int j = 0;j<=m;j++)
     {
         dp[0][j] = 0;
     }
     for(int i = 1;i<=n;i++)
     {
         for(int j =1;j<=m;j++)
         {
             if(s[i-1]==t[j-1])
             {
                 dp[i][j] = 1 + dp[i-1][j-1];
             }
             else
             {
                 dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
             }
         }
     }
     return dp[n][m];
    }
    int LongestPalindromicSubs(string &s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        return f(s,t);
    }
public:
    int minInsertions(string s) {
        int ans = LongestPalindromicSubs(s);
        int size = s.size();
        return size-ans;
    }
};
