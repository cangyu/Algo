/*
ID: yhcy1991
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

long long f[10005] = { 0 };//大数据可能会溢出
long long coinage[30] = { 0 };

int main(int argc, char **argv)
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int v, n;
	cin >> v >> n;
	for (int i = 1; i <= v; i++)
		cin >> coinage[i];

	f[0] = 1;
	for (int i = 1; i <= v; i++)//有可能起始的货币就比total value大，不能预先假定在step1 f全为1
		for (int j = coinage[i]; j <= n; j++)//从该种货币最大面值找起
			f[j] += f[j - coinage[i]];

	cout << f[n] << endl;
	return 0;
}
