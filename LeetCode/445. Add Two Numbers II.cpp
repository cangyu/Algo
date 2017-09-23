/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//利用Stack，归并
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> num1, num2, ans;
        
        ListNode *l = l1;
        while(l)
        {
            num1.push(l->val);
            l = l->next;
        }
        
        l = l2;
        while(l)
        {
            num2.push(l->val);
            l = l->next;
        }
        
        int carry = 0;
        while(!num1.empty() && !num2.empty())
        {
            int d1 = num1.top();
            num1.pop();
            int d2 = num2.top();
            num2.pop();
            
            int cur = d1+d2+carry;
            ans.push(cur%10);
            carry = cur/10;
        }
        
        while(!num1.empty())
        {
            int d1 = num1.top();
            num1.pop();
            
            int cur = d1+carry;
            ans.push(cur%10);
            carry = cur/10;
        }
        
        while(!num2.empty())
        {
            int d2 = num2.top();
            num2.pop();
            
            int cur = d2+carry;
            ans.push(cur%10);
            carry = cur/10;
        }
        
        if(carry)
            ans.push(carry);
        
        ListNode *ret=new ListNode(-1);
        ListNode *cur=ret;
        while(!ans.empty())
        {
            int d = ans.top();
            ans.pop();
            
            cur->next = new ListNode(d);
            cur = cur->next;
        }
        
        ListNode *tmp = ret;
        ret = ret->next;
        delete tmp;
        return ret;
    }
};
