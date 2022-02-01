//Brute force 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
         int size = nums.size();
        vector<int> ans;
       
        for(int i=0;i<size;i++)
        {
             int elem = nums[i]*nums[i];
             ans.push_back(elem);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

Follow up: find an O(n) solution

//Approach 1
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        int size = nums.size();
        for(int i=0; i<size; i++)
        {
            int elem = nums[i]*nums[i];
            while(!st.empty() && st.top()<elem)
           {
             int elem1 = st.top();
             ans.push_back(elem1);
                st.pop();
           }
            st.push(elem);
         
        }
        while(!st.empty())
        {
            int elem1 = st.top();
            st.pop();
            ans.push_back(elem1);
        }
        return ans;
    }
};

//Approach 2
vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start=0;
        int end=n-1;
        
        vector <int> res(n);
        int pos = n-1;
        
        while(start <= end)
        {
            if(abs(nums[start]) < abs(nums[end])) {
                res[pos--] = nums[end] * nums[end];
                end--;
            } else{
                res[pos--] = nums[start] * nums[start];
                start++;
            }
        }
        
        return res;
    }