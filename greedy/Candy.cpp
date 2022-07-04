TC: O(N)
Space: O(1)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        int res=0;
        if(size<=1)
            return size;
        vector<int> ans(size,1);
        for(int i=1;i<size;i++)        //[1,2,2,3,4]
        {
              if(ratings[i-1]<ratings[i])
                  ans[i]=ans[i-1]+1;
        }
        for(int i=size-1;i>0;i--)            //[1,2,5,4,3]
        {
           if(ratings[i-1]>ratings[i])
               ans[i-1]=max(ans[i]+1,ans[i-1]);
        }
        for(auto i:ans)
        {
            res+=i;
        }
        return res;
    }
};