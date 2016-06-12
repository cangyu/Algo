class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int nearest=nums[0]+nums[1]+nums.back();
        //���ݵ�һ��Ԫ�ط���
        for(size_t i=0;i<nums.size()-2;i++)
        {
            size_t left=i+1,right=nums.size()-1;
            while(left<right)//��ָ��
            {
                int curSum=nums[i]+nums[left]+nums[right];
                if(abs(curSum-target)<abs(nearest-target))
                    nearest=curSum;
                    
                if(curSum<target)
                    left++;
                else if(curSum>target)
                    right--;
                else
                    return curSum;
            }
        }
        return nearest;
    }
};