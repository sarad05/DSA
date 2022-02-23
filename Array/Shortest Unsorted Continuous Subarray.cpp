//Brute Force 
TC: O(NlogN)
Space: O(N)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int n = nums.size();
        int i=0,j=n-1;
        while(i<n && nums[i]==sorted[i])
        {
            i++;
        }
        while(j>i && nums[j]==sorted[j])
        {
            j--;
        }
        return j-i+1;
    }
};

//Optimal Approach
TC: O(N)
Space: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         int min_elem = INT_MAX, max_elem = INT_MIN;
        int n = nums.size();
        
        for(int i = 1; i < n; i++){
            //Decreasing Value
            if(nums[i] < nums[i-1]) {
                min_elem = min(min_elem,nums[i]);
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            //Increasing value
            if(nums[i] > nums[i+1]){
                max_elem = max(max_elem,nums[i]);
            }
        }
        if(min_elem == INT_MAX && max_elem == INT_MIN) return 0;
        
        int start = 0, end = n-1;
        
        for(; start < n; start++) {
            if(nums[start] > min_elem) break;
        }
        
        for(; end >= 0; end--) {
            if(nums[end] < max_elem) break;
        }
        
        return end-start+1;
    }
};

