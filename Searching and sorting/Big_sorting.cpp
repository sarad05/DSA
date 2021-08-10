#include<bits/stdc++.h>
using namespace std;
bool compfunc(string str1,string str2)
{
    if(str1.size()==str2.size())
    {
        return str1<str2;
    }
    else{
     return str1.size()<str2.size();
    } 
}
void sortstring(vector<string> &str,int n)
{
    sort(str.begin(),str.end(),compfunc);
    for(auto itr:str)
    {
        cout<<itr<<" ";
    }
}
int main()
{
    vector<string> v={"23451","213","54678","12","234526785432"};
    int n=v.size();
    sortstring(v,n);
    return 0;
}