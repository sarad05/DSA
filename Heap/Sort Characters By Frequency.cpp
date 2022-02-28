/*The idea is to use max heap with nodes containing a pair {frequency, character}. Since the first element of the pair is frequency, we don't need to pass a custom comparator. Max heap will be constructed on the basis of frequency of characters, i.e. the root will contain the character with maximum frequency.

Time Complexity: O(n)
O(26log(n)) = O(log(n)) For Construction and extraction from heap
O(n) For storing the frequency in hashmap.
*/
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> max_heap;
        unordered_map<char,int> mp;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
           mp[s[i]]++;
        }
        for(auto it:mp)
        {
            max_heap.push({it.second,it.first});
        }
        while(!max_heap.empty())
        {
            int top_freq = max_heap.top().first;
            while(top_freq--)
            {
                ans+=(max_heap.top().second);
            }
            max_heap.pop();
        }
        return ans;
    }
};