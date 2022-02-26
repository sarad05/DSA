
class Solution{
   private:
int countGreatersThanMid(vector<int>& arr,int mid,int n)
{
    int i = 0;
    int j = n-1;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
       while(j>i && arr[i]+arr[j]<mid)
       {
           j--;
       }
        //i can form pairs
        //with all elements in between i and j
        if(j>i)  cnt+=(j-i);
    }
    return cnt;
}
 public: 
int KthStrong(int n, int k, vector < int > arr) {
    //sort according to descending
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    
    int low = arr[n-2]+arr[n-1];
    int high = arr[0]+arr[1];
    int ans = low;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(countGreatersThanMid(arr,mid,n)>=k)
        {
            ans=mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
   }
};