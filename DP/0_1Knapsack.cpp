#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int cap;
    cin>>cap;
    vector<vector<int>> dp(n+1,vector<int> (cap+1));
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            if(j>=wt[i-1])
            {
                if(dp[i-1][j-wt[i-1]]+val[i-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i-1][j-wt[i-1]]+val[i-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][cap];
    return 0;
}