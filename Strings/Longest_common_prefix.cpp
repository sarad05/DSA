#include<bits/stdc++.h>
using namespace std;
string common_prefix(string str1,string str2)
{
   string ans;
   for(int i=0,j=0;i<str1.length() && j<str2.length();i++,j++)
   {
       if(str1[i]!=str2[j])
       {
           break;
       }
       ans.push_back(str1[i]);
   }
   return ans;
}
string find_prefix(vector<string> &str)
{   string prefix=str[0];
    for(int i=1;i<=str.size()-1;i++)
    {
        prefix=common_prefix(prefix,str[i]);
    }
    return prefix;
}
int main()
{
    vector<string> v={"flower","flow","float"};
    string ans=find_prefix(v);
    if(ans.size())
    {
        cout<<"Longest common prefix :"<<ans<<endl;
    }
    else{
        cout<<"No prefix is possible"<<endl;
    }
    return 0;
}