//Approach 1- Using sorting and Hashmap

TC: O(N*KlogK)
Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mymap;
        int n = strs.size();
        string temp;
        
        for(int i =0;i<n;++i)
        {
            temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        
        vector<vector<string> > result;
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr)
            result.push_back(itr->second);
        
        return result;
    }
};

//Method 2 Most Optimized
//Using Hashmap of Hashmap

TC: O(N*K)
Space: O(N)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& my_list) {
  map<map<char, int>, vector<string>> my_map;
    for(string str : my_list)
    {
        // Counting the frequency of the
        // characters present in a string
        map<char, int> temp_map;
        vector<string> temp_my_list;
        for(int i = 0; i < str.length(); ++i)
        {
            temp_map[str[i]]++;
        }
         
        // If the same frequency of characters
        // are already present then add that
        // string into that arraylist otherwise
        // created a new arraylist and add that
        // string
          auto it = my_map.find(temp_map);
          if (it != my_map.end())
          {
             it->second.push_back(str);
          }
        
        or,
        
        //the line 46 - 50 is same as 55 - 58
        if(my_map.find(temp_map)!=my_map.end())
        {
            my_map[temp_map].push_back(str);
        }
        else
        {
            temp_my_list.push_back(str);
            //my_map.insert({ temp_map, temp_my_list });
            my_map[temp_map] = temp_my_list;
        }
    }
     
    // Stores the result in a vector
    vector<vector<string>> result;
 
    for(auto it = my_map.begin();
             it != my_map.end(); ++it)
    {
        result.push_back(it->second);
    }
        return result;
    }
};