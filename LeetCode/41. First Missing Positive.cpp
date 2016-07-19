class Solution
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        const int n=nums.size();
        for(int i=0;i<n;i++)
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])//利用下标与数值的映射关系！
                swap(nums[i],nums[nums[i]-1]);
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                return i+1;
        return n+1;
    }
};