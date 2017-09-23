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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *t1=head,*t2=NULL,*temp;
        while(t1)
        {
            temp=t2;
            t2=t1;
            t1=t1->next;
            t2->next=temp;
        }
        return t2;
    }
};
