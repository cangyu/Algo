/*
ID: yhcy1991
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, p;
int total;
double s;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main(int argc, char **argv) 
{
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);

	cin >> n >> m >> p;
	s = p*m / 2.0;
	total = gcd(n, m) + gcd(abs(n - p), m) + p;

	int ans = s + 1 - total / 2;
	cout << ans << endl;

	return 0;
}
