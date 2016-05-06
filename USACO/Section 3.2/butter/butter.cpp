/*
ID: yhcy1991
PROG: butter
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct edge
{
	int end;
	int w;
	edge *next;
	edge():end(0),w(0),next(NULL) {}
};

struct ver
{
	edge *head;
	ver():head(NULL) {}
};

struct node
{
	int dst;
	int len;
	node():dst(0),len(0) {}
};

int N, P, C;
int place[505] = { 0 };
ver pasture[805];
edge path[3000];

const int notExist = 2147483647;

node dist[805];
int m[805];

bool known[805] = { false };

void dijkstra(int s);
void adjustHeap(int i);
void percolateDown(int i, int last);

int main(int argc, char **argv)
{
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);

	cin >> N >> P >> C;
	for (int i = 0; i < N; i++)
		cin >> place[i];

	int start, end, len;
	int pCnt = 0;
	for (int i = 0; i < C; i++)
	{
		cin >> start >> end >> len;
		path[pCnt].end = end;
		path[pCnt].w = len;
		path[pCnt].next = pasture[start].head;
		pasture[start].head = &path[pCnt];
		pCnt++;
		path[pCnt].end = start;
		path[pCnt].w = len;
		path[pCnt].next = pasture[end].head;
		pasture[end].head = &path[pCnt];
		pCnt++;
	}

	int ans = notExist;
	for (int i = 1; i <= P; i++)
	{
		dijkstra(i);
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			if (dist[m[place[i]]].len == notExist)
			{
				total = notExist;
				break;
			}
			else
				total += dist[m[place[i]]].len;
		}ans = min(ans, total);
	}

	cout << ans << endl;

	return 0;
}

void dijkstra(int s)
{
	for (int i = 1; i <= P; i++)
	{
		known[i] = false;
		dist[i].dst = i;
		dist[i].len = notExist;
		m[i] = i;
	}
	dist[s].len = 0;
	adjustHeap(s);

	for (int i = 1; i < P; i++)
	{

		int u = dist[1].dst;
		int minLen = dist[1].len;
		known[u] = true;

		int last = P + 1 - i;
		swap(dist[1], dist[last]);
		swap(m[dist[1].dst], m[dist[last].dst]);
		last--;
		percolateDown(1, last);

		edge *t = pasture[u].head;
		while (t)
		{
			if (!known[t->end])
			{
				if (dist[m[t->end]].len == notExist || dist[m[t->end]].len > minLen + t->w)
				{
					dist[m[t->end]].len = minLen + t->w;
					adjustHeap(t->end);
				}
			}
			t = t->next;
		}
	}
}

void adjustHeap(int i)
{
	int hole = m[i];
	while (hole > 1)
	{
		int parent = hole / 2;
		if (dist[parent].len == notExist || dist[parent].len > dist[hole].len)
		{
			swap(m[dist[parent].dst], m[dist[hole].dst]);
			swap(dist[parent], dist[hole]);
			hole = parent;
		}
		else
			break;
	}
}

void percolateDown(int i, int last)
{
	if (i >= last)
		return;

	int child = 2 * i;

	if (child <= last)
	{
		if (child + 1 <= last && dist[child + 1].len < dist[child].len)
			child++;
		if (dist[i].len > dist[child].len)
		{
			swap(dist[i], dist[child]);
			swap(m[dist[i].dst], m[dist[child].dst]);
		}
		else
			return;
	}

	percolateDown(child, last);
}