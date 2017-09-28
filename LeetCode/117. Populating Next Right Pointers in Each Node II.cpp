/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        TreeLinkNode *front,*iter,*pre_valid;
        bool nextfront_found=true;
        front=root;
        while(front && nextfront_found)
        {
            iter=front;
            nextfront_found=false;
            pre_valid=NULL;
            while(iter)
            {
                if(iter->left)//存在左孩子
                {
                    if(!nextfront_found)//查找下一个front
                    {
                        front=iter->left;
                        nextfront_found=true;
                    }
                    
                    if(pre_valid)
                        pre_valid->next=iter->left;
                    else
                        pre_valid=iter->left;
                        
                    if(iter->right)
                    {
                        iter->left->next=iter->right;
                        pre_valid=iter->right;
                    }
                    else
                        pre_valid=iter->left;
                    
                }
                else//无左孩子
                {
                    if(iter->right)//存在右孩子
                    {
                        if(!nextfront_found)
                        {
                            front=iter->right;
                            nextfront_found=true;
                        }
                        if(pre_valid)
                        {
                            pre_valid->next=iter->right;
                            pre_valid=pre_valid->next;
                        }
                        else
                            pre_valid=iter->right;
                    }
                }
                iter=iter->next;
            }
        }
    }
};