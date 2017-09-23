class Solution
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int lgs_sum=nums[0],cur_sum=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(cur_sum<0)
                cur_sum=nums[i];
            else
                cur_sum+=nums[i];
            if(cur_sum>lgs_sum)
                lgs_sum=cur_sum;
        }
        return lgs_sum;
    }
};