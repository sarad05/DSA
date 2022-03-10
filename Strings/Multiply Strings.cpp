class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        
        //Base conditions
        if(n==0 || m==0 || num1=="0" || num2=="0"){
            return "0";
        }
        if(num1=="1")
        {
            return num2;
        }
        if(num2=="1")
        {
            return num1;
        }
        
        //Result can be maximum of length M+N
        //For Example 99*999 = 98901 (Result is of length 5)
        vector<int> result(m+n);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int product = (num1[i]-'0')*(num2[j]-'0');
                product+=result[i+j+1]; // if we have any carry over here then add to the product
                
                //Adding the new product into the result array
                result[i+j+1] = product%10;    //storing carry value if any
                result[i+j]+=product/10;
            }
        }
        string str = "";
        for(int n:result)
        {
            if(str.empty() && n==0)   //if the result contains any trailing 0 number
            {
                continue;
            }
            str+=to_string(n);
        }
        return str;
    }
};