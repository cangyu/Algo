class Solution 
{
public:
    int rob(vector<int>& nums)
    {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return nums[0]>nums[1] ? nums[0] : nums[1];
            
        int t1=nums[0]+helper(nums,2,nums.size()-2);
        int t2=helper(nums,1,nums.size()-1);
        return t1>t2 ? t1 : t2;
    }
private:
    int helper(vector<int>& nums, int start, int end)
    {
        vector<int> res;
        res.push_back(nums[start]);
        if(start==end)
            return res[0];
        res.push_back(nums[start]>nums[start+1] ? nums[start] : nums[start+1]);
        if(start==end-1)
            return res[1];
        for(int i=2;i<=end-start;++i)
        {
            int t1=nums[start+i]+res[i-2];
            int t2=res[i-1];
            res.push_back(t1>t2 ? t1 : t2);
        }
        return res[end-start];
    }
};