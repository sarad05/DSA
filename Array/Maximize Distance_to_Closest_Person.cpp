//Brute approach
Time O(N) Space O(N)

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();  
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        
        int leftone=-1;
        int rightone=-1;
        int maxdes=0;
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                leftone=i;
            }
            else
            {
                left[i]=leftone;
            }
            
        }
           for(int i=n-1;i>=0;i--)
          {
            if(seats[i]==1)
            {
                rightone=i;
            }
             else
               {
                 right[i]=rightone;  
               }
           }
         for(int i=0;i<n;i++)
         {
             if(seats[i]==0)
             {
                 int leftdes = (left[i]!=-1) ? i-left[i] : INT_MAX;
                 int rightdes = (right[i]!=-1) ? right[i]-i : INT_MAX;
                  int currdes = min(leftdes,rightdes);
             if(currdes>maxdes)
             {
                 maxdes=currdes;
             }
         }
         }
        
        return maxdes;
    } 
};

//optimal approach
Time complexity:  O(N) Space O(1)

 int maxDistToClosest(vector<int>& seats) {
          int res = 0, n = seats.size(), last = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                res = last < 0 ? i : max(res, (i - last) / 2);
                last = i;
            }
        }
        res = max(res, n - last - 1);
        return res;
        
    } 