//Recursive Approach

class Solution {
    private:
      int f(int i,int j,string &s1,string &s2)
      {
          if(i<0)   return j+1;
          if(j<0)   return i+1;
          if(s1[i]==s2[j])
          {
              return 0 + f(i-1,j-1,s1,s2);
          }
          
         return 1 + min(f(i,j-1,s1,s2), min(f(i-1,j,s1,s2),f(i-1,j-1,s1,s2)));
      }
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        return f(size1-1,size2-1,word1,word2);
    }
};


//Memoization Approach

class Solution {
    private:
      int f(int i,int j,string &s1,string &s2,vector<vector<int>>& dp)
      {
          if(i<0)   return j+1;
          if(j<0)   return i+1;
          if(dp[i][j]!=-1)   return dp[i][j];
          if(s1[i]==s2[j])
          {
              return 0 + f(i-1,j-1,s1,s2,dp);
          }
          
         return dp[i][j] = 1 + min(f(i,j-1,s1,s2,dp), min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
      }
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1,vector<int>(size2,-1));
        return f(size1-1,size2-1,word1,word2,dp);
    }
};


//Tabulation Approach

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
        for(int i = 0 ;i<=size1;i++)
        {
            dp[i][0] = i;    //now we are using 1 based index due to which returning i instead of i+1
        }
        for(int j = 0; j<=size2 ;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=size1;i++)
        {
            for(int j=1;j<=size2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[size1][size2];
    }
};

//Space Optimization 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<int> prev(size2+1,0),curr(size2+1,0);
        for(int j = 0; j<=size2 ;j++){
            prev[j] = j;
        }
        for(int i=1;i<=size1;i++)
        {   curr[0] = i;
            for(int j=1;j<=size2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    curr[j] = 0 + prev[j-1];
                }
                else
                {
                    curr[j] = 1 + min(prev[j],min(curr[j-1],prev[j-1]));
                }
            }
            prev = curr;
        }
        return prev[size2];
    }
};