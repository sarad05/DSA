//Using maxheap
Time Complexity: O(nlog(m)log(n))
Space Complexity: O(n)

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min_elem = INT_MAX,res = INT_MAX;
        int size = nums.size();
        priority_queue<int> max_heap;
    //making all the elements in the array as even
    
    for(int elem : nums)
    {
        if(elem&1)
        {
            elem*=2;
        }
        max_heap.push(elem);
        min_elem = min(min_elem,elem);
    }
        while(max_heap.top()%2==0)
        {
            res = min(res,max_heap.top()-min_elem);  //finding minimum deviation
            int num = max_heap.top()/2;
            min_elem = min(min_elem,max_heap.top()/2);   //updating min_elem as heap will take care only for 
            max_heap.pop();                              //max_elem
            max_heap.push(num);
        }
        return min(res,max_heap.top()-min_elem);
    }
};

Approach 2:
//Using set
Time Complexity= O(n * log(n));

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set <int>  s;
        
        // Storing all  elements  in sorted order
        //insert even directly and odd with one time multiplication
        //and it will become even
        for(int i = 0; i<nums.size() ; ++i)
        {
            if(nums[i] % 2 == 0)
                s.insert(nums[i]);
            
            else
                // Odd number are transformed
                // using 2nd operation
                s.insert(nums[i] * 2);
        }
        
        // maximum - minimun
        int diff = *s.rbegin() - *s.begin();
        
        //run the loop untill difference is minimized
        while(*s.rbegin() % 2 == 0)
        {
            
            // Maximum element of the set
            int x = *s.rbegin();
            s.erase(x);
            // remove begin element and inserted half of it for minimizing
            s.insert(x/2);
            
            diff = min(diff, *s.rbegin() - *s.begin());
        }
        return diff;
    }
};
