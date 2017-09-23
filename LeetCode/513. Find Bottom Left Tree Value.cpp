/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//按层遍历,BFS
class Solution
{
public:
    int findBottomLeftValue(TreeNode* root)
    {
        TreeNode *ans=nullptr;
        queue<TreeNode*> qval = queue<TreeNode*>();
        
        qval.push(root);
        while(!qval.empty())
        {
            ans = qval.front();
            queue<TreeNode*> next_level=queue<TreeNode*>();
            while(!qval.empty())
            {
                TreeNode *tmp = qval.front();
                qval.pop();
                if(tmp->left)
                    next_level.push(tmp->left);
                if(tmp->right)
                    next_level.push(tmp->right);
            }
            qval = next_level;
        }
        
        return ans->val;
    }
};
