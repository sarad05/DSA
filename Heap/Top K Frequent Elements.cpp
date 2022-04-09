class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        //sorting elements on the basis of element frequency
        
        for(auto it:mp)
        {
            min_heap.push({it.second,it.first});
            if(min_heap.size()>k)
            {
                min_heap.pop();
            }
        }
        vector<int> ans;
        while(min_heap.size())
        {
            int elem = min_heap.top().second;
            min_heap.pop();
            ans.push_back(elem);
        }
        return ans;
    }
};