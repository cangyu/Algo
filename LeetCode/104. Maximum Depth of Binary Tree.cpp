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
    int maxDepth(TreeNode* root) //Recursive
    {
        if(!root)
            return 0;
        
        int h1=maxDepth(root->left);
        int h2=maxDepth(root->right);
        
        return max(h1,h2)+1;
    }
};

class Solution
{
public:
    int maxDepth(TreeNode* root) //Iterative-BFS
    {
        int ret=0;
        if(!root)
            return ret;
            
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            ++ret;
            const int n=q.size();
            for(int i=0;i<n;++i)
            {
                TreeNode *p=q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
        }
        
        return ret;
    }
};

class Solution 
{
public:
    int maxDepth(TreeNode* root)//Iterative-DFS
    {
        int ret = 0;
        if(!root)
            return 0;
        
        stack<pair<TreeNode*,int>> st;
        st.push(make_pair(root, 1));

        while(!st.empty())
        {
            auto tmp = st.top();
            st.pop();
            
            TreeNode *t = tmp.first;
            int cur_dep = tmp.second;
            
            if(cur_dep>ret)
                ret=cur_dep;
            
            if(t->right)
                st.push(make_pair(t->right, cur_dep+1));
            if(t->left)
                st.push(make_pair(t->left, cur_dep+1));
        }
        
        return ret;
    }
};