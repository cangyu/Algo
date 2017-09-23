class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double cmax = 0.0;
        int csum = 0.0;
        
        for(int i=0;i<k;i++)
            csum+=nums[i];
        cmax = 1.0*csum/k;
        
        int n = nums.size();
        for(int i=k;i<n;i++)
        {
            csum+=nums[i];
            csum-=nums[i-k];
            double tmx = 1.0*csum/k;
            if(tmx>cmax)
                cmax = tmx;
        }
        
        return cmax;
    }
};