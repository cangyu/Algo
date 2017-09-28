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
    bool hasPathSum(TreeNode* root, int sum)
    {
        TreeNode *last=nullptr;
        TreeNode *current=root;
        int total=0;
        stack<TreeNode*> st;
        while(current || !st.empty())
        {
            while(current)
            {
                total+=current->val;
                st.push(current);
                current=current->left;
            }
            current=st.top();
            if(!current->left && !current->right && total==sum)
                return true;
            if(current->right && current->right != last)
                current=current->right;
            else
            {
                st.pop();
                last=current;
                total-=current->val;
                current=nullptr;
            }
        }
        return false;
    }
};