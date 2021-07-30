/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers, representing n elements.
3. You are required to find the maximum sum of a subsequence with no adjacent elements.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int inc=v[0];
    int exc=0;
    for(int i=1;i<n;i++)
    {
        int ninc=exc+v[i];
        int nexc=max(inc,exc);
        inc=ninc;
        exc=nexc;
    }
    cout<<max(inc,exc);
}
