/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//��λ�Ĵ���
//ѭ������ʽ��ÿ��while��ʼʱl1��l2��ָ��ǰ������ڵ㣬tָ���Ѿ���������һ���ڵ㣬carry����һ����������������Ҫ���õ���һ��������
//����ͷ���delete�������ⲻ��Ҫ��memory leek
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(-1);
		ListNode *t = head;
		int digit = 0, carry = 0;
		while (l1 && l2)
		{
			digit = l1->val + l2->val + carry;
			t->next = new ListNode(digit % 10);
			t = t->next;
			carry = digit / 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			digit = l1->val + carry;
			t->next = new ListNode(digit % 10);
			t = t->next;
			carry = digit / 10;
			l1 = l1->next;
		}
		while (l2)
		{
			digit = l2->val + carry;
			t->next = new ListNode(digit % 10);
			t = t->next;
			carry = digit / 10;
			l2 = l2->next;
		}
		if (carry)
			t->next = new ListNode(carry);

		t = head->next;
		delete head;
		return t;
	}
};