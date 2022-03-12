//Recursion
class Solution {
    private:
       int lps(int i,int j,string &s,string &t)
       {
           if(i<0 || j<0)
           {
               return 0;
           }
           if(s[i] == t[j])
           {
               return 1 + lps(i-1,j-1,s,t);
           }
           return 0 + max(lps(i-1,j,s,t),lps(i,j-1,s,t));
       }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int size = s.size();
        int size2 = t.size();
        //cout<<s2;
       // int size2 = s2.size();
        return lps(size-1,size-1,s,t);
    }
};


//Memoization
class Solution {
    private:
       int lps(int i,int j,string &s,string &t,vector<vector<int>> &dp)
       {
           if(i<0 || j<0)
           {
               return 0;
           }
           if(dp[i][j]!=-1)   return dp[i][j];
           if(s[i] == t[j])
           {
               return dp[i][j] = 1 + lps(i-1,j-1,s,t,dp);
           }
           return dp[i][j] = 0 + max(lps(i-1,j,s,t,dp),lps(i,j-1,s,t,dp));
       }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int size = s.size();
        int size2 = t.size();
        vector<vector<int>> dp(size,vector<int>(size2,-1));
        //cout<<s2;
       // int size2 = s2.size();
        return lps(size-1,size-1,s,t,dp);
    }
};

//Tabulation
class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j<=m;j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
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
};