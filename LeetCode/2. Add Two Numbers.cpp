/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//进位的处理
//循环不变式：每次while开始时l1和l2均指向当前待处理节点，t指向已经处理的最后一个节点，carry是上一次运算的遗留结果，要被用到下一次运算中
//最后把头结点delete掉，避免不必要的memory leek
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