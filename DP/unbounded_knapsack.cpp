#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int cap;
    cin>>cap;
    vector<int> dp(cap+1);
    dp[0]=0;
    for(int bagc=1;bagc<=cap;bagc++)    //bagc=bag capacity
    { int max=0;
         for(int i=0;i<n;i++)
       {
        if(wt[i]<=bagc)
        {
            int rbagc=bagc-wt[i];     //rbagc=remaining bag capacity
            int rbagv=dp[rbagc];      //rbagv=remaining bag value
            int tbagv=rbagv+val[i];   //tbagv=total bag value
            if(tbagv>max)
            {
                max=tbagv;
            }
        }
      }
      dp[bagc]=max; 
    }
    cout<<dp[cap];
    return 0;
}