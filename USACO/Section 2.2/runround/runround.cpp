/*
ID: yhcy1991
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

long long n;

int a[10], place[10], times[10];

bool check(long long x);

int main(int argc, char **argv)//这种做法是check的思维，也可以从generate的角度来考虑
{
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);

	cin >> n;
	n++;
	while (!check(n))
		n++;

	cout << n << endl;
	return 0;
}

bool check(long long x)
{
	memset(a, 0, sizeof(a));
	memset(times, 0, sizeof(times));
	for (int i = 0; i < 10; i++)
		place[i] = -1;

	int len = 0;
	while (x)
	{
		int t = x % 10;
		if (t == 0)
			return false;
		if (place[t] != -1)
			return false;

		a[len] = t;
		place[t] = 0;
		len++;
		x /= 10;
	}

	int i = 0, j = len - 1;
	while (i < j)
	{
		swap(a[i], a[j]);
		i++;
		j--;
	}
	for (int i = 0; i < len; i++)
		place[a[i]] = i;

	int cnt = len;
	int startIndex = 0;
	int nextIndex;
	times[a[startIndex]]++;
	cnt--;

	while (cnt)
	{
	    nextIndex = (startIndex + a[startIndex]) % len;
		if (times[a[nextIndex]] == 0)
			times[a[nextIndex]] = 1;
		else
			return false;

		cnt--;
		startIndex = nextIndex;
	}

	nextIndex = (startIndex + a[startIndex]) % len;
	return nextIndex == 0;
}
