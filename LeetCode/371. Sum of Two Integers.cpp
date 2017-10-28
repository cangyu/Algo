class Solution 
{
public:
    int getSum(int a, int b) 
    {
        int ans = 0;
        
        while(b)
        {
            ans = a^b; //without carry
            b = (a&b)<<1; //carry
            a = ans;
        }
        
        return ans;
    }
};