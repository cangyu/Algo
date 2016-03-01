#include<iostream>

using namespace std;

typedef struct node {
	int data;
	node* next;
	node(int a) :data(a), next(NULL) {}
}NodeTypeDef, *pNodeTypeDef;

int search(pNodeTypeDef head, int x);
void clean(pNodeTypeDef head);

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	pNodeTypeDef head, tail;
	head = tail = new NodeTypeDef(0);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		tail->next = new NodeTypeDef(x);
		tail = tail->next;
	}

	int m;
	cin >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		cnt += search(head, t);
	}

	cout << cnt << endl;

	clean(head);

	//system("pause");
	return 0;
}

int search(pNodeTypeDef head, int x)
{
	pNodeTypeDef pre = head, cur = head->next;

	int cnt = 0;
	while (cur)
	{
		++cnt;
		if (cur->data == x)
		{
			pre->next = cur->next;
			cur->next = head->next;
			head->next = cur;
			return cnt;
		}
		pre = cur;
		cur = cur->next;
	}
	return cnt;
}

void clean(pNodeTypeDef head)
{
	pNodeTypeDef pre = head, cur = head->next;

	while (cur)
	{
		delete pre;
		pre = cur;
		cur = cur->next;
	}
	delete pre;
}