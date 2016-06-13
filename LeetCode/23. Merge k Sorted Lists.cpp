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
    typedef ListNode *pListNode;
    
    struct myCmp
    {
        bool operator()(const pListNode &lhs, const pListNode &rhs)
        {
            return lhs->val>rhs->val;//�����Ǵ����ǰ
        }
    };

    //�ռ临�Ӷ�:O(K)
    //ʱ�临�Ӷ�:��K�����й���n��Ԫ�أ�����ÿ��Ԫ�ض�Ҫ����һ�Ρ�����һ�Σ����������ѵĵ����������O(nlogK)
    //����ⲿ���򣬻�����ν��ʤ����/����������һ������IO���������Ӷ�����
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pListNode,vector<pListNode>, myCmp> pq;
        
        for(auto t:lists)
        {
            if(t)
                pq.push(t);
        }
        
        ListNode Head(-1);//����һ������Ľڵ�����һ������
        pListNode tail=&Head;
        
        while(!pq.empty())
        {
            tail->next=pq.top();
            pq.pop();
            tail=tail->next;
            if(tail->next)
                pq.push(tail->next);
        }
        
        return Head.next;
    }
};