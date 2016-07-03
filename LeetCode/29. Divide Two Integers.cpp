class Solution
{
public:
    int divide(int dividend, int divisor) 
    {
        
        if(divisor==0 || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;
        
        int sign=(dividend<0)^(divisor<0) ? -1 :1;
        int ans=0;
        
        unsigned int a=dividend>=0? dividend : -dividend;
        unsigned int b=divisor>=0? divisor: -divisor;
        
        for(int i=31;i>=0;i--)
        {
            if(a>>i >= b)
            {
                ans+=1<<i;
                a-=b<<i;
            }
        }
        
        return sign<0 ? -ans : ans;
    }
};
