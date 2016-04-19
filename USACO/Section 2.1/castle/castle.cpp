/*
ID: yhcy1991
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int dn[4] = { 0, -1, 1, 0 };
const int dm[4] = { 1, 0, 0, -1};
const char d[4] = { 'E', 'N', 'S', 'W' };

#define WEST 1
#define NORTH 2
#define EAST 4
#define SOUTH 8

inline bool _check_bound(int i, int j, int n, int m);
void dfs(int n, int m, int **b, int i, int j, int **s, int cnt, int *t);
bool isConnected(int **b, int i, int j, int ni, int nj);
inline bool rowConCheck(int **b, int i, int j1, int j2);
inline bool colConCheck(int **b, int j, int i1, int i2);

/*
题面表达的意思是不是错了？farthest to the west? farthest to the south? 是closest to the west/sourth,也即是左下角优先，且west优先于sourth
在找两个连起来最大时此处条件判断条件要带等号，否则会漏掉后面的
按提议，在同一位置，应该先检测east，再是north，才能在east和north同时满足的情况下最后的结果是north
*/

int main()
{
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	int m, n;
	fin >> m >> n;

	int **b = new int*[n];
	for (int i = 0; i < n; i++)
		b[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fin >> b[i][j];

	int **s = new int*[n];
	for (int i = 0; i < n; i++)
		s[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s[i][j] = -1;

	int cnt = 0;
	int *t = new int[n*m];
	memset(t, 0, n*m*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == -1)
			{
				dfs(n, m, b, i, j, s, cnt, t);
				cnt++;
			}
		}
	}

	fout << cnt << endl;
	int max_area = 0;
	for (int i = 0; i < cnt; i++)
		max_area = max(max_area, t[i]);
	fout << max_area << endl;
	

	int total = 0, tn = 0, tm = 0, td = 0;
	for (int j = m - 1; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nei_n = i + dn[dir], nei_m = j + dm[dir];
				if (_check_bound(nei_n, nei_m, n, m))
				{
					if (s[i][j] != s[nei_n][nei_m] && t[s[i][j]] + t[s[nei_n][nei_m]] >= total)
					{
						total = t[s[i][j]] + t[s[nei_n][nei_m]];
						tn = i;
						tm = j;
						td = dir;
					}
				}
			}
		}
	}
	fout << total << endl;
	fout << tn + 1 << ' ' << tm + 1 << ' ' << d[td] << endl;


	for (int i = 0; i < n; i++)
	{
		delete[] b[i];
		delete[] s[i];
	}
	delete[] b;
	delete[] s;
	delete[] t;

	fin.close();
	fout.close();
	return 0;
}

inline bool _check_bound(int i, int j, int n, int m)
{
	return  0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int n, int m, int **b, int i, int j, int **s, int cnt, int *t)
{
	if (s[i][j] != -1)
		return;

	s[i][j] = cnt;
	t[cnt]++;

	for (int dir = 0; dir < 4; dir++)
	{
		int nei_n = i + dn[dir], nei_m = j + dm[dir];
		if (_check_bound(nei_n, nei_m, n, m))
		{
			if (s[nei_n][nei_m] == -1 && isConnected(b, i, j, nei_n, nei_m))
				dfs(n, m, b, nei_n, nei_m, s, cnt, t);
		}
	}
}

bool isConnected(int **b, int i, int j, int ni, int nj)
{
	if ((i != ni && j != nj) || (i == ni && j == nj))
		return false;

	if (i == ni)
		return j < nj ? rowConCheck(b, i, j, nj) : rowConCheck(b, i, nj, j);
	else
		return i < ni ? colConCheck(b, j, i, ni) : colConCheck(b, j, ni, i);
}

inline bool rowConCheck(int **b, int i, int j1, int j2)
{
	int req1 = b[i][j1] & EAST;
	int req2 = b[i][j2] & WEST;
	return !req1 && !req2;
}

inline bool colConCheck(int **b, int j, int i1, int i2)
{
	int req1 = b[i1][j] & SOUTH;
	int req2 = b[i2][j] & NORTH;
	return !req1 && !req2;
}
