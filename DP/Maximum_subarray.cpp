#include<bits/stdc++.h>
using namespace std;
int maximum_subarray(vector<int> &nums)
{   int n=nums.size();
    vector<int>dp(n);
        dp[0]=nums[0];
        int max_element=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]>0?nums[i]+dp[i-1]:nums[i];
            max_element=max(max_element,dp[i]);
        }
        return max_element;
}
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int ans=maximum_subarray(nums);
    cout<<ans<<endl;
    return 0;
}
