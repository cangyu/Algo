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
    void flatten(TreeNode* root)
    {
        TreeNode *cur=root;
        while(cur)
        {
            if(cur->left)
            {
                TreeNode* pre=cur->left;
                while(pre->right)
                    pre=pre->right;
                pre->right=cur->right;
                cur->right=cur->left;
                cur->left=nullptr;
            }
            cur=cur->right;
        }
    }
};

//Recursive
class Solution 
{
public:
    void flatten(TreeNode* root)
    {
        if(!root)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        if(root->left)
            swap(root->left,root->right);
        if(root->left && root->right)
        {
            auto t=root->right;
            while(t->right)
                t=t->right;
            t->right=root->left;
            root->left=NULL;
        }
    }
};