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
    int closestValue(TreeNode* root, double target) 
    {
        int a = root->val;
        TreeNode* nxt = target<a ? root->left : root->right;
        
        if(!nxt)
            return a;
        
        int b = closestValue(nxt, target);
        return fabs(a-target)<fabs(b-target) ? a : b;
    }
};