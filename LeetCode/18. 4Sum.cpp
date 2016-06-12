class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        const int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-3;i++)
        {
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)//¼ôÖ¦
                break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target)
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
                    break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target)
                    continue;
                int left=j+1,right=n-1;
                while(left<right)
                {
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target)
                        left++;
                    else if(sum>target)
                        right--;
                    else
                    {
                        ans.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(left<right && nums[left-1]==nums[left]);
                        do{right--;}while(left<right && nums[right]==nums[right+1]);
                    }
                }
                while(j+1<n-2 && nums[j]==nums[j+1])//È¥ÖØ
                    j++;
            }
            while(i+1<n-3 &&nums[i]==nums[i+1])
                i++;
        }
        
        return ans;
    }
};