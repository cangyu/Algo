/*
ID: yhcy1991
PROG: fence
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
	int x;
	node *next;
	node(int i=0,node *p=NULL):x(i),next(p) {}
};

int m[502][502];
int degree[502];
int f = 0, verMax = 0;

node *dfs(int start, node* &end);

int main(int argc, char **argv)
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	memset(m, 0, sizeof(m));
	memset(degree, 0, sizeof(degree));

	cin >> f;
	for (int i = 0; i < f; i++)
	{
		int a, b;
		cin >> a >> b;
		m[a][b]++;
		m[b][a]++;
		degree[a]++;
		degree[b]++;
		verMax = max(verMax, max(a, b));
	}

	int start = 0;
	for (int i = 1; i <= verMax; i++)
	{
		if (degree[i] % 2 == 1)
		{
			start = i;
			break;
		}
	}
	if (start == 0)
	{
		for (int i = 1; i <= verMax; i++)
		{
			if (degree[i] != 0)
			{
				start = i;
				break;
			}
		}
	}

	node head, *tail;
	head.next = dfs(start, tail);

	while (1)
	{
		node *p = &head, *pos = NULL;
		while (p->next)
		{
			if (degree[p->next->x] > 0)//因为要按照字典序，所以要从最后一个开始
				pos = p;
			
			p = p->next;
		}

		if (!pos)
			break;

		node *tb, *te;
		tb = dfs(pos->next->x, te);

		te->next = pos->next->next;
		node *tmp = pos->next;
		pos->next = tb;
		delete tmp;
	}

	node *t = head.next, *prev = NULL;
	while (t)
	{
		if (prev)
			delete prev;
		cout << t->x << endl;
		t = t->next;
		delete prev;
	}

	return 0;
}

node *dfs(int start, node* &end)
{
	node *begin = end = new node(start);

	int cur = end->x;
	while (degree[cur] > 0)
	{
		for (int i = 1; i <= verMax; i++)
		{
			if (m[cur][i] > 0)
			{
				m[cur][i]--;
				m[i][cur]--;
				degree[cur]--;
				degree[i]--;
				end->next = new node(i);
				end = end->next;
				cur = i;
				break;
			}
		}
	}
	return begin;
}