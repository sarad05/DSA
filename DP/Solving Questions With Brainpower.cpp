//leetcode 2140

//Recursive Approach

class Solution {
    private:
         int func(int indx,vector<vector<int>>& questions)
         {    int n=questions.size();
             if(indx==n-1)
             {
                 return questions[indx][0];
             }
          if(indx>=n)  return 0;
          int pick = questions[indx][0] + func(indx + questions[indx][1] + 1,questions);
          int notpick = 0 + func(indx + 1 , questions);
          return max(pick , notpick);
         }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return func(0,questions);
    }
};

//Memoization Approach
class Solution {
    private:
        long long func(int indx,vector<vector<int>>& questions,vector<long long>& dp)
         {    
             if(indx==questions.size() - 1)
             {
                 return questions[indx][0];
             }
          if(indx>=questions.size())  return 0;
          if(dp[indx]!=-1)
          {
              return dp[indx];
          }
          long long pick = questions[indx][0] + func(indx + questions[indx][1] + 1,questions,dp);
          long long notpick = 0 + func(indx + 1 , questions, dp);
          return dp[indx] = max(pick , notpick);
         }
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        vector<long long> dp(questions.size(),-1);
        return func(0,questions,dp);
    }
};


 //Tabulation approach
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
       long long n=questions.size();
            vector<long long> dp(n,-1);
            dp[n-1] = questions[n-1][0];   //base case covered
       
          //now check from where do the loop will start and then write the same function as 
            //written in the recursive approach
            for(int indx=n-2; indx>=0 ; indx--)
            {
             long long pick = questions[indx][0];
                if(indx + questions[indx][1] + 1 < n)   //handling the case of:
                    pick+= dp[ indx + questions[indx][1] + 1 ]; //   if(indx>=questions.size())  return 0;
             long long notpick = 0 + dp[ indx + 1 ];
            dp[indx] = max(pick , notpick);
    }
        return dp[0];   //as this is the bottom most index and final answer is stored here
    }
};
    

