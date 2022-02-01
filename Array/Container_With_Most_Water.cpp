//Brute force solution

TC: O(N^2) and space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int size = height.size();
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                ans = max(ans,(j-i)*min(height[i],height[j]));
            }
        }
        return ans;
    }
};


//Optimal solution

Method: Two pointer
 
TC: O(N) and space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
         int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left<right){
            int currArea = min(height[left], height[right]) *(right - left);
            maxArea  = max(maxArea, currArea);
            if(height[left] < height[right]){
                left++;
            } else{
                right--;
            }
        }
        return maxArea;
    }
};


