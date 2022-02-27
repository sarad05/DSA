class solution{
    public:
vector<int> countChocolates(int n, int k, vector<int> arr)
{
     vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
        //this is the point where first sliding window overs
        if(i>=k)
        {
            mp[arr[i-k]]--;
            if(mp[arr[i-k]]==0)  mp.erase(arr[i-k]);
        }
        //start storing the answers from the first sliding window 
        if(i>=k-1)
        {
            ans.push_back(mp.size());
        }
    }
    return ans;
}
};
