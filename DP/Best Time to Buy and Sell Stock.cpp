class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int mini_elem  = INT_MAX;
        int n = prices.size();
        for(int i=0;i<n;i++)
        {
            if(prices[i]<mini_elem)  //this day i will buy
            {
                mini_elem = prices[i];
                
            }
            
            ans = max(ans,abs(mini_elem-prices[i]));
        }
        return ans;
    }
};