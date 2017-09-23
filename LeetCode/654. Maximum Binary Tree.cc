/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//basic recursive solution
class Solution
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return make_max_tree(nums, 0, nums.size()-1);
    }
    
    TreeNode* make_max_tree(vector<int> &nums, int left, int right)
    {
        if(left>right)
            return nullptr;
        
        int max_val = nums[left];
        int max_idx = left;
        for(int i=left+1;i<=right;i++)
        {
            if(nums[i]>max_val)
            {
                max_val = nums[i];
                max_idx = i;
            }
        }
        
        TreeNode *ret = new TreeNode(max_val);
        ret->left = make_max_tree(nums, left, max_idx-1);
        ret->right = make_max_tree(nums, max_idx+1, right);
        
        return ret;
    }
};
