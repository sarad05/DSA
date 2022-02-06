class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int oIndex = 0;
        int i = 0; // Index upto which repeatation happens
        while(i<nums.size()){

            int sIndex = i; //// Start Index of repetition
            while(i<nums.size()-1 && nums[i] == nums[i+1]){
                i++;
            }

            int length = i -sIndex + 1; // Length of repetition
            int freq = min(length, 2);

            while(freq--){
                nums[oIndex] = nums[sIndex];
                oIndex++;
            }
            i++;
        }
        return oIndex;
    }
};