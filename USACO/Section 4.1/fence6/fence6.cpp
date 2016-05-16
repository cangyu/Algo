/*
ID: yhcy1991
PROG: fence6
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 0, minLoop = 2147483647, start = 0;
int len[101] = { 0 };
int f[101][2][9] = { 0 };
bool visited[101] = { false };
int link[101][101] = { 0 };

void dfs(int cur, int in_dir, int totalLen);

int main(int argc, char **argv) 
{
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);

	cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		cin >> len[x];
		cin >> f[x][0][0] >> f[x][1][0];
		for (int j = 1; j <= f[x][0][0]; j++)
			cin >> f[x][0][j];
		for (int j = 1; j <= f[x][1][0]; j++)
		{
			cin >> f[x][1][j];
			link[x][f[x][1][j]] = 1;
		}
	}

	for (start = 1; start <= n; start++)
	{
		memset(visited, 0, sizeof(visited));
		dfs(start, 0, len[start]);
	}

	cout << minLoop << endl;

	return 0;
}

void dfs(int cur, int in_dir, int totalLen)
{
	if (totalLen >= minLoop)
		return;

	for (int i = 1; i <= f[cur][1 - in_dir][0]; i++)
	{
		int next = f[cur][1 - in_dir][i];
		if (next == start && link[start][cur] == 0) //单向找环，对于起始边只从0的一侧进，从1的一侧出
		{
			minLoop = min(minLoop, totalLen);
			return;
		}

		if (!visited[next])
		{
			visited[next] = true;
			dfs(next, link[next][cur], totalLen + len[next]);
			visited[next] = false;
		}
	}
}
