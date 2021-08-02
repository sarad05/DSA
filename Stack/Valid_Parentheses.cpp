#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        int n=s.length();
        map<char,char> mp;
        mp['(']=')';
        mp['{']='}';
        mp['[']=']';
        stack<char> st;
        for(auto a:s)
        {  
            if(st.size())
          {
           if(mp[st.top()]==a)
           {
            st.pop();
            }
            else
            {
           st.push(a);
            }
          }
          else
          {
              st.push(a);
          }
        }
        return st.empty();
}
int main()
{
    string str="{[()]}";
    bool ans=isValid(str);
    cout<<ans<<endl;
    return 0;
}