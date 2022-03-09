Recursive Approach
-----------

int func(int ind,vector<int>&price,int len)
{
    if(ind==0)
    {
        return len*price[0];
    }
    int notTake = 0 + func(ind-1,price,len);
    int take = INT_MIN;
    int rod_length = ind+1;
    if(rod_length<=len)
    {
        take = price[ind] + func(ind,price,len-rod_length);
    }
    return max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    return func(n-1,price,n);
}


Memoization 
------------------

int func(int ind,vector<int>&price,int len,vector<vector<int>>& dp)
{
    if(ind==0)
    {
        return len*price[0];
    }
    if(dp[ind][len]!=-1)   return dp[ind][len];
    int notTake = 0 + func(ind-1,price,len,dp);
    int take = INT_MIN;
    int rod_length = ind+1;
    if(rod_length<=len)
    {
        take = price[ind] + func(ind,price,len-rod_length,dp);
    }
    return dp[ind][len] = max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return func(n-1,price,n,dp);
}



Tabulation
-----------

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int len=1;len<=n;len++)
    {
        dp[0][len] = len*price[0];
    }
    for(int ind = 1;ind<n;ind++)
    {
        for(int len = 1; len<=n; len++)
        {
            int notTake = 0 + dp[ind-1][len];
            int take = INT_MIN;
            int rod_length = ind+1;
            if(rod_length<=len)
            {
                take = price[ind] + dp[ind][len-rod_length];
            }
            dp[ind][len] = max(take,notTake);
        }
    }
    return dp[n-1][n];
}


//space optimization

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int len=1;len<=n;len++)
    {
        prev[len] = len*price[0];
    }
    for(int ind = 1;ind<n;ind++)
    {
        for(int len = 1; len<=n; len++)
        {
            int notTake = 0 + prev[len];
            int take = INT_MIN;
            int rod_length = ind+1;
            if(rod_length<=len)
            {
                take = price[ind] + curr[len-rod_length];
            }
            curr[len] = max(take,notTake);
        }
        prev = curr;
    }
    return prev[n];
}
