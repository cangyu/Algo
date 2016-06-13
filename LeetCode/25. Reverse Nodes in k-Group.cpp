/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution//����������Ҳ����д�ɵݹ���ʽ������
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode dummy(-1);
        dummy.next=head;
        
        ListNode *preLeft=&dummy,*left=head,*right=NULL;
        while(left)
        {
            right=left;
            for(int i=1;i<k;i++)
            {
                if(right->next)
                    right=right->next;
                else
                    return dummy.next;
            }
            reverseKNodes(preLeft,left,right,k);
            preLeft=left;//ע�����ﲻ��right������left����Ϊǰ���Ѿ�ת�ù���
            left=left->next;//ע���ͬ��
        }
        return dummy.next;
    }
    
private:
    void reverseKNodes(ListNode * &preLeft, ListNode *left, ListNode *right, int k)
    {
        if(k<2)
            return;
        
        ListNode *postRight=right->next, *cur=left->next;
        
        left->next=postRight;
        while(cur!=postRight)
        {
            ListNode *t=cur;
            cur=cur->next;
            t->next=preLeft->next;
            preLeft->next=t;
        }
    }
};