class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> hashset;
        for(int num:nums)
        {
            hashset.insert(num);
        }
        int longestStreak = 0;
        for(int num:nums)
        {
            if(!hashset.count(num-1))
            {
                int currentnum = num;
                int currentStreak = 1;
                
                while(hashset.count(currentnum+1))
                {
                    currentnum+=1;
                    currentStreak+=1;   
                }
                longestStreak = max(longestStreak,currentStreak);
            }
        }
        return longestStreak;
    }
};