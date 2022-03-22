//slight variation of LCS here just need to check if i!=j when s1[i] == s2[j] that is same character should not belong to same index

//Recursive approach

class Solution {
    private:
    int f(int i,int j,string& str1,string &str2){
        if(i<0 || j<0)  return 0;
        if(str1[i]==str2[j] && i!=j)
        {
            return 1 + f(i-1,j-1,str1,str2);
        }
        return max(f(i-1,j,str1,str2),f(i,j-1,str1,str2));
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    return f(n,n,str,str);
		}
};

//Memoization

class Solution {
    private:
    int f(int i,int j,string& str1,string &str2,vector<vector<int>>&dp){
        if(i==0 || j==0)  return 0;
        if(dp[i][j]!=-1)  return dp[i][j];
        if(str1[i-1]==str2[j-1] && i-1!=j-1)
        {
            return dp[i][j] = 1 + f(i-1,j-1,str1,str2,dp);
        }
        return dp[i][j] = max(f(i-1,j,str1,str2,dp),f(i,j-1,str1,str2,dp));
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    return f(n,n,str,str,dp);
		}

};

