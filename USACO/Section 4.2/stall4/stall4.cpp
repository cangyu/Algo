/*
ID: yhcy1991
PROG: stall4
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std; 

int n = 0, m = 0;
int c[204][204] = { 0 };
int match[204] = { 0 };
bool visited[204] = { false };

bool Hungary(int k);

/*���Ի���������������Сƥ�䣬�����и��õ��������㷨*/
int main(int argc, char **argv)
{
	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i][0];
		for (int j = 1; j <= c[i][0]; j++)
			cin >> c[i][j];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Hungary(i))
			ans++;
		memset(visited, 0, sizeof(visited));
	}

	cout << ans << endl;

	return 0;
}

bool Hungary(int k)
{
	for (int i = 1; i <= c[k][0]; i++)
	{
		int cur_stall = c[k][i];
		if (!visited[cur_stall])
		{
			visited[cur_stall] = true;
			if (!match[cur_stall] || Hungary(match[cur_stall]))//������˻����ó�����������
			{
				match[cur_stall] = k;
				return true;
			}
		}
	}
	return false;
}
