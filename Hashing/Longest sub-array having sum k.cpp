class Solution{
    public:
           int lenOfLongSubarr(vector<int>arr,int k)
        {
            int n = arr.size();
                unordered_map<int, int> um;
                int sum = 0, maxLen = 0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];           //taking prefix sum 
                    if (sum == k)
                        maxLen = i + 1;
                    if (um.find(sum) == um.end())
                        um[sum] = i;
                    if (um.find(sum - k) != um.end()) {
                        if (maxLen < (i - um[sum - k]))
                            maxLen = i - um[sum - k];
                    }
                }
                return maxLen;
        }
};