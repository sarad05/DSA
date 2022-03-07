// Intitution is saying start with the largest alphabet in the string
//insert that string less than the repeatLimit and after that insert second largest in ans then if 
//largest is still left then insert that largest in ans in this way we can acheive lexicographically largest
//string
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26] = {0};
        for(auto it:s)
        {
            cnt[it-'a']++;
        }
        priority_queue<pair<int,int>> max_heap;
        for(int i=0;i<26;i++)
        {
           if(cnt[i]>0) max_heap.push({i,cnt[i]});
        }
        
        string ans = "";
        while(!max_heap.empty())
        {
            //the largest guy with its frequency
            int char1 = max_heap.top().first;
            int frq1 = max_heap.top().second;
            max_heap.pop();
            
            //when no element is there in the string i.e ans.size()==0 
            //or when zzc that is c not equal to z
            if(ans.size()==0 || ans.back()!=char(char1+'a'))    //bbab case
            {
                int times = min(frq1,repeatLimit);
                
                for(int j=0;j<times;j++)
                {
                    ans+=(char)(char1+'a');    //converting from string to int
                }
                frq1-=times;
                
                //are you still left then still this char is the largest then again              
                //push this into the max_heap;
                if(frq1){
                    max_heap.push({char1,frq1});
                }
            }
            else   //give me the second largest
            {
                if(max_heap.size()==0)  break;
                int char2 = max_heap.top().first;
                int frq2 = max_heap.top().second;
                max_heap.pop();
                //add one occurrence of it
                ans+=(char)(char2+'a');
                frq2--;
                
                if(frq2)           //at this moment c will not be there a will be 
                {                  //there so a will be top now if a left then push it
                    max_heap.push({char2,frq2});
                }
                max_heap.push({char1,frq1});     //pushing original top most in heap
            }
        }
        return ans;
    }
};