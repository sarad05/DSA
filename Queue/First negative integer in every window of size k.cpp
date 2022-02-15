//Using Sliding Window 
class Solution{
    public:
              vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
                list<long long int> l;
                vector<long long int>v;
                long long int i=0,j=0;
                while(j<N)
                {
                    if(A[j]<0)
                    {
                        l.push_back(A[j]);
                    }
                    if(j-i+1<K)
                    {
                        j++;
                    }
                    else if(j-i+1==K)
                    {
                        if(l.empty())
                        {
                            v.push_back(0);
                        }
                        else
                        {
                            v.push_back(l.front());
                            if(A[i]==l.front())
                            {
                                l.pop_front();
                            }
                        }
                        i++;
                        j++;
                    }
                }
                return v;

}
};