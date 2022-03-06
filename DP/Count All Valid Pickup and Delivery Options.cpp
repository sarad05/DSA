class Solution {
public:
 
    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
 
    #define ll long long
    #define MOD 1000000007
    int countOrders(int n) {
        // dp[i] = number of ways for first i + 1 orders
        vector<ll> dp(n);
        dp[0] = 1;
 
        for(int i=1;i<n;i++){
            ll gaps = i*2 + 1;
            ll ways = (gaps*gaps) - (gaps*(gaps-1))/2;
 
            dp[i] = (dp[i-1]*ways)%MOD;
        }
 
        return dp[n-1];
    }
};