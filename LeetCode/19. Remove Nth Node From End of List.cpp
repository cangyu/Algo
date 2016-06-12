/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head)
            return NULL;
            
        ListNode *t=head;
        int len=0;
        while(t)
        {
            ++len;
            t=t->next;
        }
        
        ListNode *pre=NULL,*cur=head;
        for(int i=0;i<len-n;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        
        if(pre)
            pre->next=cur->next;
        else
            head=cur->next;//Corner case: need to delete the head node!
        
        return head;
    }
};