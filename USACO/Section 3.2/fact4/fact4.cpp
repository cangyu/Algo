/*
ID: yhcy1991
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[11] = { 0 };

int main(int argc, char **argv)//由于n并不大，也可以将1-n全部存入，然后同样处理，先去掉所有的5，再去掉相应的2，最后尾数做乘法
{
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);

	int n;
	cin >> n;

	int ans = 1;

	int round = n / 10;
	for (int i = 0; i < round; i++)
	{
		for (int j = 1; j <= 10; j++)
			a[j] = 10 * i + j;

		int cnt5 = 0;
		for (int j = 5; j <= 10; j += 5)
		{
			while (a[j] % 5 == 0)
			{
				a[j] /= 5;
				cnt5++;
			}
		}

		for (int j = 2; j <= 10; j += 2)
		{
			while (cnt5 && a[j] % 2 == 0)
			{
				cnt5--;
				a[j] /= 2;
			}
		}

		for (int j = 1; j <= 10; j++)
		{
			ans *= (a[j] % 10);
			ans %= 10;
		}
	}

	/*Handle the remaining numbers*/
	int left = n - round * 10;
	int k = 1;
	while (k <= left)
	{
		a[k] = 10 * round + k;
		k++;
	}

	int cnt5_tail = 0;
	for (int j = 1; j <= left; j++)
	{
		while (a[j] % 5 == 0)
		{
			a[j] /= 5;
			cnt5_tail++;
		}
	}
	for (int j = 1; j <= left; j++)
	{
		while (cnt5_tail && a[j] % 2 == 0)
		{
			a[j] /= 2;
			cnt5_tail--;
		}
	}
	for (int j = 1; j <= left; j++)
	{
		ans *= (a[j] % 10);
		ans %= 10;
	}


	cout << ans << endl;
	
	return 0;
}
