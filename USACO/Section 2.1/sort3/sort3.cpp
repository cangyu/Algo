/*
ID: yhcy1991
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	int a[1005], b[1005];
	int c[4][4] = { 0 };
	int n, ans = 0;

	fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n);

	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			c[a[i]][b[i]]++;
	}

	ans += min(c[1][2], c[2][1]);
	ans += min(c[2][3], c[3][2]);
	ans += min(c[3][1], c[1][3]);
	ans += 2 * abs(c[1][2] - c[2][1]);

	fout << ans << endl;

	fin.close();
	fout.close();
	return 0;
}
