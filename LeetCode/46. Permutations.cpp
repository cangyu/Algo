class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        
        dfs(nums, 0, ans);
        
        return ans;
    }
    
    void dfs(vector<int> &nums, int cur_pos, vector<vector<int>> &ret)
    {
        if(cur_pos==nums.size())
        {
            ret.push_back(nums);
            return;
        }
        
        for(int i=cur_pos;i<nums.size();i++)
        {
            swap(nums[cur_pos], nums[i]);
            dfs(nums, cur_pos+1, ret);
            swap(nums[cur_pos], nums[i]);
        }
    }
};