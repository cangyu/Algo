/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        
        while(!q.empty())
        {
            queue<TreeNode*> cq;
            vector<int> cl;
            while(!q.empty())
            {
                TreeNode *t = q.front();
                q.pop();
                cl.push_back(t->val);
                
                if(t->left)
                    cq.push(t->left);
                if(t->right)
                    cq.push(t->right);
            }
            
            q = cq;
            ans.push_back(cl);
        }
        
        return ans;
    }
};