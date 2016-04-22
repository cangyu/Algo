/*
ID: yhcy1991
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

void check(int x);

char roman[7] = { 'I','V','X','L','C','D','M' };
int a[7] = { 0 };

int main()
{
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		check(i);

	for (int i = 0; i < 7; i++)
	{
		if (a[i] != 0)
			cout << roman[i] << ' ' << a[i] << endl;
	}

	return 0;
}

void check(int x)
{
	int i = 0;
	while (x)
	{
		int c = x % 10;
		switch (c)
		{
		case 1:
		case 2:
		case 3: a[2 * i] += c; break;
		case 4: a[2 * i]++; a[2 * i + 1]++; break;
		case 5: a[2 * i + 1]++; break;
		case 6:
		case 7:
		case 8: a[2 * i] += c - 5; a[2 * i + 1]++; break;
		case 9: a[2 * i]++; a[2 * i + 2]++; break;
		default: break;
		}
		i++;
		x /= 10;
	}
}

