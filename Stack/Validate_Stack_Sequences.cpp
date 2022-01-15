//TC: O(N) Space:O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> st;
        int n=pushed.size();
        int m=popped.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
           st.push(pushed[i]);
           while(!st.empty() && st.top()==popped[j])
             {
                 st.pop();
                 j++;
             }
        }
            return st.empty();
    }
};

//Time O(N)  Space O(1)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for (int x : pushed) {
            pushed[i++] = x;
            while (i > 0 && pushed[i - 1] == popped[j])
                --i, ++j;
        }
        return i == 0;
    }
};