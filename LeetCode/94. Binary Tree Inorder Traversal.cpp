/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Iterative
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<pair<TreeNode*, int>> buf;
        pair<TreeNode*, int> cur;
        
        if(root)
            buf.push(make_pair(root, 0));
        
        while(!buf.empty())
        {
            cur = buf.top();
            buf.pop();
            ++cur.second;
            
            if(cur.second==1)
            {
                buf.push(cur);
                TreeNode *left = cur.first->left;
                if(left)
                    buf.push(make_pair(left, 0));
            }
            else
            {
                ans.push_back(cur.first->val);
                TreeNode *right = cur.first->right;
                if(right)
                    buf.push(make_pair(right, 0));
            }
        }
        
        return ans;
    }
};

//Morris
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        TreeNode *cur=root, *pre=nullptr;
        
        while(cur)
        {
            if(cur->left)
            {
                pre = cur->left;
                while(pre->right && pre->right!=cur)
                    pre = pre->right;
                
                if(pre->right)
                {
                    pre->right=nullptr;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
                else
                {
                    pre->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return ans;
    }
};
