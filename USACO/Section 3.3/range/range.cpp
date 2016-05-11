/*
ID: yhcy1991
PROG: range
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int cnt[256] = { 0 };
int m[256][256] = { 0 };

int main(int argc, char **argv)//从能得到的最大的正方形的角度出发来处理，可以将重叠的情况归一化处理
{
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);

	cin >> n;
	char t = getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			t = getchar();
			if (t == '1')
				m[i][j] = 1;
		}
		t = getchar();
	}

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = n - 1; j >= 1; j--)
		{
			if (m[i][j] == 1)
			{
				m[i][j] += min(m[i][j + 1], min(m[i + 1][j], m[i + 1][j + 1]));
				if (m[i][j] >= 2)
				{
					for (int k = 2; k <= m[i][j]; k++)
						cnt[k]++;
				}
			}
		}
	}

	for (int k = 2; k <= n; k++)
	{
		if (cnt[k] != 0)
			cout << k << ' ' << cnt[k] << endl;
	}

	return 0;
}

