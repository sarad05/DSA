/*
1. You are given a number n.
2. You are required to print the number of binary strings of length n with no consecutive 0's.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> dp_0(n+1);
    vector<int> dp_1(n+1);
    dp_1[1]=1;
    dp_0[1]=1;
    for(int i=2;i<=n;i++)
    {   dp_1[i]=dp_1[i-1]+dp_0[i-1];
        dp_0[i]=dp_1[i-1];
       
    }
    cout<<dp_1[n]+dp_0[n];
    return 0;
}
