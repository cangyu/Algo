/*
ID: yhcy1991
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int f[105][105] = { 0 }, visited[105] = { false };
int n = 0, maxIndex = 0;
int cnt[105] = { 0 };

void dfs(int x);

int main(int argc, char **argv)
{
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		int i, j, p;
		cin >> i >> j >> p;
		maxIndex = max(maxIndex, max(i, j));
		f[i][j] = p;
	}

	for (int i = 1; i <= maxIndex; i++)
	{
		fill_n(visited + 1, maxIndex, false);
		fill_n(cnt + 1, maxIndex, 0);
		dfs(i);
		for (int j = 1; j <= maxIndex; j++)
		{
			if (cnt[j] > 50 && j != i)
				cout << i << ' ' << j << endl;
		}
	}

	return 0;
}

void dfs(int x)
{
	if (visited[x])
		return;
	visited[x] = true;

	int i = maxIndex;
	while (i >= 1)
	{
		cnt[i] += f[x][i];
		if (cnt[i] > 50)
			dfs(i);
		i--;
	}
}
