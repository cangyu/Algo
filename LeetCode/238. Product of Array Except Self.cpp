//From back and end, two run
//Time: O(n)
//Space: O(1)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int t=1;
        int n = nums.size();
        vector<int> ret = vector<int>(n);
        ret[n-1] = 1;
        
        //Init
        for(int i=n-2;i>=0;i--)
            ret[i]=nums[i+1]*ret[i+1];
        
        //Iterate
        for(int i=0;i<n;i++)
        {
            ret[i]*=t;
            t*=nums[i];
        }
        
        return ret;
    }
};
