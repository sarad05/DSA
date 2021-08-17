 #include<bits/stdc++.h>
 using namespace std;
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int smaller=matrix[0][0];
        int n=matrix.size();
        int m=matrix[0].size();
        int larger=matrix[n-1][m-1];
        if(target<smaller || target>larger)
        {
            return false;
        }
        if(!n)
        {
         return false;
        }
        int low=0;
        int high=(m*n)-1;
        while(low<=high)
        {
          int mid=(low+(high-low)/2);
            if(matrix[mid/m][mid%m]==target)
            {
                return true;
            }
            else if(target>matrix[mid/m][mid%m])
            {
                low=low+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
int main()
{
vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  int target=13;
   cout<<boolalpha<<searchMatrix(mat,target);
   //cout<<boolalpha<<ans;
   return 0;
}