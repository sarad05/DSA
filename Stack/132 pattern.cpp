
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       stack<int> st;
      int second_max = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(second_max>nums[i])
            {
                return true;
            }
            while(!st.empty() && nums[i] > st.top())
            {
                int elem = st.top();
                st.pop();
               if(elem > second_max)
               {
                   second_max = elem;
               }
            }
            st.push(nums[i]);
        }
        return false;
    }
};