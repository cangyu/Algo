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
        if(!root)
            return;
        TreeLinkNode *p=root,*cur=NULL;
        while(p->left)//不变式：每次循环开始时p所指向的那一行的next都已经被连接上。
        {
            cur=p;
            while(cur)
            {
                cur->left->next=cur->right;
                if(cur->next)
                    cur->right->next=cur->next->left;
                cur=cur->next;
            }
            p=p->left;
        }
    }
};