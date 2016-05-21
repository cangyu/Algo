/*
ID: yhcy1991
PROG: ditch
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int c[205][205] = { 0 };
int pre_node[205] = { 0 };
int m = 0, n = 0;

int Edmonds_Karp();
int bfs();

/* Based on Edmonds-Karp algorithm, the time complexity is O(VE^2)*/
int main(int argc, char **argv) 
{
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);

	cin >> n >> m;
	int u, v, capacity;
	for (int i = 1; i <= n; i++)
	{
		cin >> u >> v >> capacity;
		c[u][v] += capacity;
	}

	int ans = Edmonds_Karp();

	cout << ans << endl;

	return 0;
}

int Edmonds_Karp()
{
	int ans = 0, cur_aug = 0;
	while ((cur_aug = bfs()) != -1)
	{
		int cur = m;//Start from the end
		while (cur != 1)//The start point is 1
		{
			int pre = pre_node[cur];
			c[pre][cur] -= cur_aug;//Substract the remaining capacity
			c[cur][pre] += cur_aug;//Add the reverse
			cur = pre;
		}
		ans += cur_aug;
	}

	return ans;
}

int bfs()
{
	int cur_f = 2147483647;
	queue<int> q;
	q.push(1);
	fill_n(pre_node + 1, m, -1);
	pre_node[1] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == m)
			break;

		for (int i = 1; i <= m; i++)
		{
			if (pre_node[i] == -1 && c[cur][i] != 0)
			{
				pre_node[i] = cur;
				cur_f = min(cur_f, c[cur][i]);
				q.push(i);
			}
		}
	}

	if (pre_node[m] == -1)
		return -1;
	else
		return cur_f;
}
