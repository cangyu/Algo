class Solution
{
public:
    int minSteps(int n) 
    {
        if(n<=1)
            return 0;
        else if(n%2==0)
            return minSteps(n/2)+2;
        else
        {
            int min_stp=INT_MAX;
            for(int i=n-1;i>=1;i--)
            {
                if(n%i==0)
                    min_stp=min(min_stp, minSteps(i)+n/i);
            }
            return min_stp;
        }
    }
};