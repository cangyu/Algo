class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        //虽然被rotate了，仍可用二分法找到Pivot
        int left=0,right=nums.size()-1,mid=-1;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right=mid;
        }
        
        int minIndex=left;
        int maxIndex=(left+nums.size()-1)%nums.size();
        
        if(target>=nums[0] && target<=nums[maxIndex])
            left=0,right=maxIndex;
        else if(target>=nums[minIndex] && target<=nums[nums.size()-1])
            left=minIndex,right=nums.size()-1;
        else
            return -1;
        
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(target<nums[mid])
                right=mid-1;
            else if(target>nums[mid])
                left=mid+1;
            else
                return mid;
        }
        return -1;
    }
};
