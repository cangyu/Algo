/*
ID: yhcy1991
PROG: job
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int sa[32] = { 0 }, sb[32] = { 0 };
int ea[32] = { 0 }, eb[32] = { 0 };
int a[1004] = { 0 }, b[1004] = { 0 };

int main(int argc, char **argv) 
{
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);

	int n, m1, m2;
	cin >> n >> m1 >> m2;

	for (int i = 1; i <= m1; i++)
		cin >> sa[i];
	for (int i = 1; i <= m2; i++)
		cin >> sb[i];

	for (int i = 1; i <= n; i++)
	{
		int mi = -1, mt = 2147483647;
		for (int j = 1; j <= m1; j++)
		{
			int t = ea[j] + sa[j];
			if (t < mt)
			{
				mi = j;
				mt = t;
			}
		}

		a[i] = mt;
		ea[mi] = mt;
	}

	for (int i = 1; i <= n; i++)//同样方法处理b
	{
		int mj = -1, mt = 2147483647;
		for (int j = 1; j <= m2; j++)
		{
			int t = eb[j] + sb[j];
			if (t < mt)
			{
				mj = j;
				mt = t;
			}
		}

		b[i] = mt;
		eb[mj] = mt;
	}

	int total = 0;
	for (int i = 1; i <= n; i++)
		total = max(total, a[i] + b[n + 1 - i]);

	cout <<a[n]<<' '<< total << endl;

	return 0;
}
