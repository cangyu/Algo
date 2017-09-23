/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Recursive way
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        else
            return helper(root->left,root->right);
    }
    bool helper(TreeNode *t1,TreeNode *t2)
    {
        if(!t1 && !t2)
            return true;
        else if(!t1 || !t2)
            return false;
        else
        {
            if(t1->val==t2->val)
                return helper(t1->left,t2->right) && helper(t1->right,t2->left);//Key Point
            else
                return false;
        }
    }
};

//Iterative way
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        left.push(root->left);
        right.push(root->right);
        while(!left.empty() && !right.empty())
        {
            TreeNode *p=left.front();
            left.pop();
            TreeNode *q=right.front();
            right.pop();
            
            if(!p && !q)
                continue;
            if(!p || !q)
                return false;
            if(p->val != q->val)
                return false;
            else
            {
                left.push(p->left);right.push(q->right);
                left.push(p->right);right.push(q->left);
            }
        }
        return true;
    }
};
