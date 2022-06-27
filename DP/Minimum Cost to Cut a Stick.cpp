//Tabulation

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
       int size = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(size+2,vector<int>(size+2,0));
        for(int i=size;i>=1;i--)
        {
           for(int j=1;j<=size;j++)
           {if(i>j)  continue;
               int mini = 1e9;
               for(int ind = i;ind<=j;ind++)
               {
                   int cnt = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                   mini = min(mini,cnt);
               }
            dp[i][j] = mini;
           }
        }
        return dp[1][size];
    }
};

//Memoization

class Solution {
    int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)  return 0;
        if(dp[i][j]!=-1)  return dp[i][j];
        int mini = 1e9;
        for(int ind = i;ind<=j;ind++)
        {
            int cnt = cuts[j+1] - cuts[i-1] + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
            mini = min(mini,cnt);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(size + 1,vector<int>(size + 1,-1));
        return f(1,size,cuts,dp);
    }
};
*/