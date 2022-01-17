class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> arr;
        string str = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!str.empty())
                    arr.push_back(str);
                str.clear();
            }
            else{
                str.push_back(s[i]);
            }
        }
        if(!str.empty())
            arr.push_back(str);
        if(pattern.size()!=arr.size())
            return false;
        map<char,string> mp1;
        map<string,char> mp2;
        for(int i=0;i<pattern.length();i++){
            if(mp1.count(pattern[i])){
                if(mp1[pattern[i]]!=arr[i]){
                    return false;
                }
            }
            mp1[pattern[i]] = arr[i];
            if(mp2.count(arr[i])){
                if(mp2[arr[i]]!=pattern[i]){
                    return false;
                }
            }
            mp2[arr[i]] = pattern[i];
        }
        return true;
    }
};