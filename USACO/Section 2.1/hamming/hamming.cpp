/*
ID: yhcy1991
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool isQualify(int a, int b);

int n = 0, b = 0, d = 0;
int a[100] = { 0 };


int main()
{
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);

	cin >> n >> b >> d;

	const int up_limit = 1 << b;
	int cnt = 1;

	for (int p = 1; p < up_limit; p++)
	{
		bool flag = true;
		for (int i = 0; i < cnt; i++)
		{
			if (!isQualify(p, a[i]))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			a[cnt] = p;
			if (++cnt >= n)
				break;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (i % 10 == 0)
			cout << a[i - 1] << endl;
		else
			cout << a[i - 1] << ' ';
	}
	cout << a[n - 1] << endl;

	return 0;
}

bool isQualify(int a, int b)
{
	int num = a^b;
	num = (num & 0x55555555) + ((num & 0xAAAAAAAA) >> 1);
	num = (num & 0x33333333) + ((num & 0xCCCCCCCC) >> 2);
	num = (num & 0x0F0F0F0F) + ((num & 0xF0F0F0F0) >> 4);
	num = (num & 0x00FF00FF) + ((num & 0xFF00FF00) >> 8);
	num = (num & 0x0000FFFF) + ((num & 0xFFFF0000) >> 16);
	return num >= d;
}
