class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        set<int> mp;
        string ans ="";
        for(int i=0;i<s.size();i++)
        {  char str = s[i];
            if(str==')' || str=='(')
            {
                if(st.empty())
                {
                    st.push({str,i});
                }
                else
                {
                if(st.top().first=='(' && str==')')
                {
                    st.pop();
                }
                else
                {
                    st.push({str,i});
                }
                }
            }
        }
        while(!st.empty())
        {
            mp.insert(st.top().second);
            st.pop();
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(mp.count(i))
            {
                continue;
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};