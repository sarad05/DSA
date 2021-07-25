#include<bits/stdc++.h>
using namespace std;
vector<int> find_pairs(vector<int> &v,int target)
{
    vector<int>sol;
    map<int,int>mp;
    for(int i=0;i<v.size();i++)
    {
        int find_num=target-v[i];
        if(mp.find(find_num)!=mp.end())
        {
            sol.push_back(mp[find_num]);
            sol.push_back(i);
            return sol;
        }
        else
        {
            mp[v[i]]=i;
        }
    }
    return sol;
}
int main()
{   vector<int> v={2,7,5,6};
    int target=11;
    vector<int> ans;
    ans=find_pairs(v,target);
    cout<<"[";
    for(int i=0;i<ans.size();i++)
    {   if(i!=ans.size()-1)
        {
        cout<<ans[i]<<",";
        }
        else
        {
            cout<<ans[i]<<"]";
        }
    }
    return 0;
}