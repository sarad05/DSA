class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count = 0;
        int i = 0;
        int j = people.size()-1;
        while(i<=j)
        {
            if(people[j]==limit)
            {
                j--;
                count++;
            }
            else if(people[i]+people[j]<=limit)
            {
                count++;
                i++;
                j--;
            }
            else    
            {       
                j--;
                count++;
            }
        }
        return count;
    }
};