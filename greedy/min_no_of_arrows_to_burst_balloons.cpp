class Solution {
public:
    // Time Complexity:- O(NlogN)
    // Space Complexity:- O(1)
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](auto& p1,auto& p2){
            return p1[1]<p2[1];
        });
        int ans = 1,currend = points[0][1];
        for(int i=1;i<points.size();i++){{
            if(points[i][0]>currend){
                ans++;
                currend = points[i][1];
            }
        }}
        return ans;
    }
};