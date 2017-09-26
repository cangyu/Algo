class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int idx0=0, idx2=nums.size()-1;
        for(int i=0;i<=idx2;i++)
        {
            while(nums[i]==2 && i!=idx2)
                swap(nums[i], nums[idx2--]);
            while(nums[i]==0 && i!=idx0)
                swap(nums[i], nums[idx0++]);
        }
    }
};