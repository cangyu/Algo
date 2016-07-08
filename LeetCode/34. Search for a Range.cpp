class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        //two binary search utilizing the propertiy of biased choice
        //instead of trival one binary search followed with two while
        
        int left=0,right=nums.size()-1,mid=-1;
        vector<int> ans(2,-1);
        
        while(left<right)//要保证结束时left一定是该区间的左端，所以left只能在nums[mid]小于target时一步步挪
        {
            mid=left+(right-left)/2;//mid左偏，使得最后只有2个数时不会都不动
            if(nums[mid]<target)
                left=mid+1;
            else
                right=mid;//由于mid左偏，即使在相等时，也会带着right相对向左移
        }
        
        if(nums[left]!=target)
            return ans;
        else
            ans[0]=left;
        
        right=nums.size()-1;
        while(left<right)//要保证结束时right一定是该区间的右端，所以right只能在nums[mid]大于target时一步步挪
        {
            mid=left+(right-left+1)/2;//mid右偏
            if(target<nums[mid])
                right=mid-1;
            else
                left=mid;//由于mid右偏，使得left不会原地保持不动，一定会被带着相对向右移
        }
        ans[1]=right;
        
        return ans;
    }
};
