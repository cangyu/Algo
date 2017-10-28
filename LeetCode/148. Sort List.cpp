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
    ListNode* sortList(ListNode* head)//Cut from center and then merge
    {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *slow=head, *fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow;
        slow=slow->next;
        fast->next=nullptr;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        
        return mergeTwoLists(l1,l2);
    }
private:
    ListNode *mergeTwoLists(ListNode *p1, ListNode *p2)
    {
        ListNode *pre_head=new ListNode(-1);
        for(ListNode *p=pre_head;p1 != nullptr || p2 != nullptr;p=p->next)
        {
            int val1 = p1==nullptr ? INT_MAX : p1->val;
            int val2 = p2==nullptr ? INT_MAX : p2->val;
            
            if(val1<=val2)
            {
                p->next=p1;
                p1=p1->next;
            }
            else
            {
                p->next=p2;
                p2=p2->next;
            }
        }
        ListNode *head=pre_head->next;
        delete pre_head;
        return head;
    }
};