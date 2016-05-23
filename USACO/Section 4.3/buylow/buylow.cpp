/*
ID: yhcy1991
PROG: buylow
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

int n;
int a[5004] = { 0 };
int f[5004] = { 0 };
int c[5004] = { 0 };

using namespace std;

int main(int argc, char **argv) 
{
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);

	fill_n(f, sizeof(f) / sizeof(int), 1);

	for (int i = n - 1; i >= 1; i--)
	{
		for (int k = i + 1; k <= n; k++)
		{
			if (a[i] > a[k])
				f[i] = max(f[i], 1 + f[k]);
		}
	}

	int maxIndex = 0, fmax = -1;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] > fmax)
		{
			fmax = f[i];
			maxIndex = i;
		}
	}

	cout << fmax << ' ';

	return 0;
}
