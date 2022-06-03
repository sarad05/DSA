class Solution {
public:
 
    void solve(string s,vector<string>&ans,unordered_map<string,bool>&mp,int removals)
    {
 
        if(mp[s])
            return;
 
        mp[s]=true;
 
        if(removals==0)
        {
            //checking for valid answer
             int removals_needed=find_removals(s);
             if(removals_needed==0)
                 ans.push_back(s);
 
            return;
        }
 
        for(int i=0;i<s.length();++i)
        {
            string leftpart=s.substr(0,i);
            string rightpart=s.substr(i+1);
            string join=leftpart+rightpart;
            solve(join,ans,mp,removals-1);
        }
 
        return;
 
    }
 
    int find_removals(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(')
                st.push(s[i]);
 
            else if(s[i]==')')
            {
                if(st.size()!=0 && st.top()=='(')
                    st.pop();
 
                else
                    st.push(')');
            }
        }
 
        return st.size();
    }
 
    vector<string> removeInvalidParentheses(string s) {
 
        unordered_map<string,bool> mp;
        int min_removals=find_removals(s);
        vector<string> ans;
        solve(s,ans,mp,min_removals);
        return ans;
    }
};
