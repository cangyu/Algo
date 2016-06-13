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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) //典型的归并排序的写法，包含了各种为空的corner case
    {
        ListNode Head(-1);
        ListNode *cur=&Head;
        
        ListNode *t1=l1,*t2=l2;
        
        while(t1 && t2)
        {
            if(t1->val<t2->val)
            {
                cur->next=t1;
                t1=t1->next;
            }
            else
            {
                cur->next=t2;
                t2=t2->next;
            }
            cur=cur->next;
        }
        while(t1)
        {
            cur->next=t1;
            t1=t1->next;
            cur=cur->next;
        }
        while(t2)
        {
            cur->next=t2;
            t2=t2->next;
            cur=cur->next;
        }
        return Head.next;//use‘.' instead of '->'
    }
};