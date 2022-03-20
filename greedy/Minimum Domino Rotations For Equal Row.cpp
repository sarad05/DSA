class Solution {
    private:
     int conversionToTarget(vector<int>&tops,vector<int>&bottoms,int target){
         int topConversion = 0;
         int bottomConversion = 0;
         for(int i=0;i<tops.size();i++)
         {
             if((tops[i] != target) && (bottoms[i] != target))
             {
                 return -1;
             }
             if(tops[i]!=target && bottoms[i]==target)
             {
                 topConversion++;
             }
             if(tops[i]==target && bottoms[i]!=target)
             {
                 bottomConversion++;
             }
         }
         return min(topConversion,bottomConversion);
     }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans1 = conversionToTarget(tops,bottoms,tops[0]);
        int ans2 = conversionToTarget(tops,bottoms,bottoms[0]);
        
        if(ans1 > 0 && ans2 > 0)
        {
            return min(ans1,ans2);
        }
        else if(ans1>0)
        {
            return ans1;
        }
        else{
           return ans2;
        }
       
    }
};