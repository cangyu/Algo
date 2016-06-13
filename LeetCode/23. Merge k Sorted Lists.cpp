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
            return lhs->val>rhs->val;//本题是大的在前
        }
    };

    //空间复杂度:O(K)
    //时间复杂度:设K个序列共有n个元素，由于每个元素都要进队一次、出队一次，都会引发堆的调整，因此是O(nlogK)
    //针对外部排序，还有所谓的胜者树/败者树来进一步减少IO次数，复杂度相似
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pListNode,vector<pListNode>, myCmp> pq;
        
        for(auto t:lists)
        {
            if(t)
                pq.push(t);
        }
        
        ListNode Head(-1);//引入一个多余的节点来归一化处理
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