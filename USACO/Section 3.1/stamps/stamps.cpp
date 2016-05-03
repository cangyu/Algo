/*
ID: yhcy1991
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int k, n;
int v[52] = { 0 };

bool check(int num, int cnt);

int main(int argc, char **argv)
{
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);

	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v, v + n);
	int max_postage = k*v[n - 1];
	int i = 0;
	while (i <= max_postage && check(i, k))
		i++;

	cout << i - 1 << endl;

	return 0;
}

bool check(int num, int cnt)
{
	if (num < 0 || cnt < 0)
		return false;
	else if (num == 0)
		return true;
	else if (num > 0 && cnt == 0)
		return false;
	else
	{
		bool ans = false;
		for (int i = 0; i < n; i++)
			ans |= check(num - v[i], cnt - 1);
		return ans;
	}
}
