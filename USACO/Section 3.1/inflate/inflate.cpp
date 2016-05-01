/*
ID: yhcy1991
PROG: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int total;
int n;

int v[10005], p[10005], f[10005];

int main(int argc, char **argv)//基础的完全背包问题，可重复，不仅要考虑单位空间的价值，也要充分利用空间！！
{
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);

	memset(v, sizeof(v), 0);
	memset(p, sizeof(p), 0);
	memset(f, sizeof(f), 0);

	cin >> total >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = v[i]; j <= total; j++)
		{
			if (f[j - v[i]] + p[i] > f[j])
				f[j] = f[j - v[i]] + p[i];
		}
	}

	cout << f[total] << endl;

	return 0;
}
