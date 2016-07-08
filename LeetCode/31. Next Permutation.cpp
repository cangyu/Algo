class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        if(nums.size()<2)
            return;
        
        int i=nums.size()-1;
        while(i!=0 && nums[i-1]>=nums[i])
            i--;
        
        if(i==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        else
            i--;
        
        int j=nums.size()-1;
        while(nums[j]<=nums[i])//避免由于重复元素导致的死循环，要保证n!次调用next_permutation得到所有的全排列
            j--;
        
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};
