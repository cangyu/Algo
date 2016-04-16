class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int> > ans;
        if(nums.size()<3)
            return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int k=0;k<nums.size()-2;k++)
        {
            int target=-nums[k];
            int i=k+1,j=nums.size()-1;
            while(i<j)
            {
                if(nums[i]+nums[j]>target)
                    j--;
                else if(nums[i]+nums[j]<target)
                    i++;
                else
                {
                    vector<int> cur_ans={nums[k],nums[i],nums[j]};
                    ans.push_back(cur_ans);
                    while(i<j && nums[i]==cur_ans[1])//在自身上也要移动
                        i++;
                    while(i<j && nums[j]==cur_ans[2])
                        j--;
                }
            }
            while(k<nums.size()-2 && nums[k+1]==nums[k])
                k++;
        }
        return ans;
    }
};