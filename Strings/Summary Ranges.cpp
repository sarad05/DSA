//TimeComplexity: O(N)
//Space :O(N)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
          if(nums.empty()){
            return {};
        }
 
        int n = nums.size();
        vector<string> ans;
 
        for(int i=0;i<n;i++){
            int j = i;
            while(j+1<n and nums[j+1]==1+nums[j]){
                j++;
            }
            if(j==i){
                ans.push_back(to_string(nums[i]));
            }
            else{
                ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            }
            i = j;
        }
        return ans;
    }
};