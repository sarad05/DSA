//Using XOR
class Solution {
public:
    char findTheDifference(string s, string t) {
      char c = 0;
        for(char cs : s) c ^= cs;
        for(char ct : t) c ^= ct;
        return c;
    }
};

//Using Array

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> f(26);
        for(char c : s)
            f[c - 'a']--;
    /*debug
        for(auto elem:f)
        {
            cout<<elem<<": ";
        }
       */ 
        for(char c : t)
            f[c - 'a']++;
        int i = 0;
        for(; i < 26; i++)
            if(f[i] == 1) break;
        return (char)(i + 'a');
    }
};
