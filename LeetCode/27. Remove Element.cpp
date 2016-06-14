//类似于CLRS上快排的划分
//分段保持性质：[0,left)都不是val;[left,right)是待检测的数;right是从后往前数第一个不是val的;(right,end())都是val
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left=0,right=nums.size()-1;
        
        while(right>=0 && nums[right]==val)
            right--;
        
        while(left<right)
        {
            if(nums[left]==val)
            {
                swap(nums[left],nums[right]);
                while(left<right && nums[right]==val)
                    right--;
            }
            left++;
        }
        
        return right+1;
    }
};


//或者沿用上一题的思路，将两种序列分开
//但当val较少时会引入较多的移动
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int start=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
                nums[start++]=nums[i];
        }
        return start;
    }
};