/*
ID: yhcy1991
PROG: nuggets
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n = 0;
int a[10] = { 0 };
bool f[256];

int main(int argc, char **argv) 
{
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);

	fill_n(f, 256, false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	for (int i = 2; i <= a[0]; i++)// 无解的充分条件，所有的size能表示成同一个数的倍数，即间距同模
	{
		bool DivideAll = true;
		for (int j = 0; j < n; j++)
		{
			if (a[j] % i != 0)
			{
				DivideAll = false;
				break;
			}
		}
		if (DivideAll)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	int cnt = 0, prev = 0, cur = 1;
	f[0] = true;
	while (cnt < a[0])
	{
		bool isQualify = false;
		for (int i = 0; i < n; i++)
		{
			if (f[(cur - a[i] + a[n - 1]) % a[n - 1]])// 从余数的角度来缩减要test的情况，好！！！
			{
				isQualify = true;
				break;
			}
		}

		if (isQualify)
		{
			cnt++;
			f[cur%a[n - 1]] = true;
		}
		else
		{
			cnt = 0;
			prev = cur;
		}
		cur++;
	}

	cout << prev << endl;
	return 0;
}
