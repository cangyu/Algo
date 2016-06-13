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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode **pp=&head;
        ListNode *a,*b;
        
        while((a=*pp) && (b=a->next))
        {
            a->next=b->next;
            b->next=a;
            *pp=b;//起到改变pre的作用
            pp=&a->next;
        }
        return head;
    }
};