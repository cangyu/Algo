/*
ID: yhcy1991
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

long long f[50][1000] = { 0 };
long long dp[1000] = { 0 };

long long solver1(int n);
long long solver2(int n);

int main()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	int n;
	cin >> n;

	cout << solver2(n) << endl;

	return 0;
}

long long solver1(int n)
{
	int sum = n*(n + 1) / 2;
	if (sum % 2 != 0)
		return 0;

	f[1][0] = f[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= i*(i + 1) / 2; j++)
		{
			//f[i][j]表示前i个数中能组成和j的种数，对i分两种情况
			f[i][j] = f[i - 1][j];
			if (j >= i)
				f[i][j] += f[i - 1][j - i];
		}
	}
	int half = sum / 2;
	return f[n][half] / 2;
}

long long solver2(int n)//优化空间复杂度
{
	int sum = n*(n + 1) / 2;
	if (sum % 2 != 0)
		return 0;

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int j = i*(i + 1) / 2;
		while (j >= i)
		{
			dp[j] += dp[j - i];
			j--;
		}
	}
	return dp[sum / 2] / 2;
}
