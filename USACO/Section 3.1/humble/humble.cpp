/*
ID: yhcy1991
PROG: humble
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int k, n;
int p[105];
int curStart[105];//记录第i个质数当前的要检查的humble number的下标
int h[100005];

int main(int argc, char **argv)//逐个检查，注意用标记来剪枝
{
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);

	memset(p, sizeof(p), 0);
	memset(curStart, sizeof(curStart), 0);
	memset(h, sizeof(h), 0);
	h[0] = 1;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
		cin >> p[i];

	sort(p, p + k);

	int cnt = 1;
	while (cnt <= n)
	{
		int minh = 2147483647;
		int mini = -1;

		for (int i = 0; i < k; i++)
		{
			if (p[i] * h[curStart[i]] < minh)
			{
				minh = p[i] * h[curStart[i]];
				mini = i;
			}
		}

		h[cnt++] = minh;
		curStart[mini]++;

		/* 去重 */
		for (int j = 0; j < k; j++)
		{
			if (p[j] * h[curStart[j]] == minh)
				curStart[j]++;
		}

	}

	cout << h[n] << endl;

	return 0;
}
