/*
ID: yhcy1991
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

int k, n;
int v[52] = { 0 };

bitset<2000008> f;
bitset<2000008> tmp;

void generate(int cnt);

int main(int argc, char **argv)
{
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);

	cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		f.set(v[i]);
	}
	sort(v, v + n);
	int min_postage = v[0];
	int max_postage = k*v[n - 1];

	if (min_postage != 1)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int cnt = 2; cnt <= k; cnt++)
		generate(cnt);
	
	int i = 1;
	while (i<=max_postage && f.test(i))
		i++;

	cout << i - 1 << endl;
	return 0;
}

void generate(int round)
{
	tmp.reset();
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= (round - 1)*v[n - 1]; j++)
		{
			if (f.test(j) && !f.test(j + v[i]))
				tmp.set(j + v[i]);
		}
	}
	f |= tmp;
}
