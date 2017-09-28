class Solution
{
public:
    int findPeakElement(vector<int>& nums)//总会找到一个，用两个指针迭代逼近
    {
        int left=-1,right=nums.size();
            
        while(left+2<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[mid+1])
                right=mid+1;
            else
                left=mid;
        }
        return right-1;
    }
};