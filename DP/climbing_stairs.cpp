#include <iostream>
#include <vector>
using namespace std;

int cs(int n){
   int dp[n+1];
   dp[0]=1;
   for(int i=1;i<=n;i++){
       if(i==1)
       {
           dp[i]=dp[i-1];
       }
       else if(i==2)
       {
           dp[i]=dp[i-1]+dp[i-2];
       }
       else if(i>=3)
       {
           dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
       }
   }
    return dp[n];

}

int main(){
    int n;
    cin>>n;
    int ans=cs(n);
    cout<<ans<<endl;
    return 0;
}