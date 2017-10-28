class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int k = 0;
        for(auto t: nums)
            if(t)
                nums[k++]=t;
        
        while(k<nums.size())
            nums[k++]=0;
    }
};