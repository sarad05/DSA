/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the 
     amount "amt" can be paid.
*/
/*
Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
                  used for many installments in payment of "amt"
Note2 -> You are required to find the count of combinations and not permutations i.e.
                  2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
                  combination. You should treat them as 1 and not 3.
*/
#include<bits/stdc++.h>
using namespace std;
 int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1);
        vector<int>ans;
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
           for(int j=coins[i];j<dp.size();j++)
           {
             dp[j]+=dp[j-coins[i]];
           }
        }
        return dp[amount];
        }
int main()
{   int num;
    cin>>num;
    vector<int> v(num);
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    int amount;
    cin>>amount;
    int ans=coinChange(v,amount);
    cout<<ans;
    return 0;
}