/*
ID: yhcy1991
PROG: ratios
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long target[3] = { 0 };
long long s[3][3] = { 0 };

const long long notExist = ((long long)1 << 32);

inline long long calc_det(long long m[][3]);
inline void col_swap(long long m[][3], long long t[], int col);

int main(int argc, char **argv)
{
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);

	for (int i = 0; i < 3; i++)
		cin >> target[i];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> s[j][i];

	long long x, y, z, t;
	t = calc_det(s);

	col_swap(s, target, 0);
	x = calc_det(s);
	col_swap(s, target, 0);

	col_swap(s, target, 1);
	y = calc_det(s);
	col_swap(s, target, 1);

	col_swap(s, target, 2);
	z = calc_det(s);
	col_swap(s, target, 2);

	if (t == 0 || x*t < 0 || y*t < 0 || z*t < 0)
	{
		cout << "NONE" << endl;
		return 0;
	}

	if (t < 0)
	{
		t = -t;
		x = -x;
		y = -y;
		z = -z;
	}

	long long tmp[4] = { x,y,z,t };
	long long p = notExist;
	for (int i = 0; i < 4; i++)
	{
		if (tmp[i] == 0)
			continue;
		else
			p = min(p, tmp[i]);
	}
	if (p == notExist)
		p = 0;

	for (long long i = 2; i <= p; i++)
	{
		while (t%i == 0 && x%i == 0 && y%i == 0 && z%i == 0)
		{
			t /= i;
			x /= i;
			y /= i;
			z /= i;
			p /= i;
		}
	}

	cout << x << ' ' << y << ' ' << z << ' ' << t << endl;
	return 0;
}

inline long long calc_det(long long m[][3])
{
	return (m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1]) - (m[0][2] * m[1][1] * m[2][0] + m[0][1] * m[1][0] * m[2][2] + m[0][0] * m[1][2] * m[2][1]);
}

inline void col_swap(long long m[][3], long long t[], int col)
{
	for (int i = 0; i < 3; i++)
		swap(m[i][col], t[i]);
}