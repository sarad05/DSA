class Solution {
public:
    string removeDuplicateLetters(string s) {
    vector<int> lastSeen(26);
        vector<bool> visited(26);
        int n = s.size();
        for(int i=0;i<n;i++)  lastSeen[s[i]-'a'] = i;   //storing indexes at which elem are present lastly
        string ans = "";
        for(int i=0;i<n;i++)
        {   if(visited[s[i] - 'a'])  continue;  
            while(!ans.empty() && ans.back() > s[i] && lastSeen[ans.back()-'a'] > i)  //maintaining lexicographical order
            {
                visited[ans.back()-'a'] = false;   
                ans.pop_back();
            }
         ans.push_back(s[i]);
         visited[s[i]-'a'] = true;
        }
        return ans;
    }
};