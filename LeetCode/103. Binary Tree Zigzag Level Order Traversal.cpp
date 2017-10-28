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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) //BFS
    {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            queue<TreeNode*> next;
            vector<int> cur_ans;
            
            while(!q.empty())
            {
                TreeNode *t=q.front();
                q.pop();
                cur_ans.push_back(t->val);

                if(t->left)
                    next.push(t->left);
                if(t->right)
                    next.push(t->right);
            }
            
            q = next;
            ret.push_back(cur_ans);
        }
        
        for(int i=1;i<ret.size();i+=2)
            reverse(ret[i].begin(), ret[i].end());
        
        return ret;
    }
};

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) //DFS
    {
        vector<vector<int>> ret;
        
        dfs(root, 0, ret);
        
        for(int i=1;i<ret.size();i+=2)
            reverse(ret[i].begin(), ret[i].end());
        
        return ret;
    }
    
    void dfs(TreeNode *root, int level, vector<vector<int>> &ans)
    {
        if(!root)
            return;
        
        if(ans.size()==level)
            ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
};