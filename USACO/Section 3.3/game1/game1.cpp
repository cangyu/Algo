/*
ID: yhcy1991
PROG: game1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int a[201] = { 0 };
int n = 0;

int sum[201][201] = { 0 };
int dp[201][201][2] = { 0 };

/**
  * 根据先手和后手dp, 注意两者之和一定为sum 
  */
int main(int argc, char **argv) 
{
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i][i][0] = a[i];
		sum[i][i] = a[i];
	}

	for (int targetLen = 2; targetLen <= n; targetLen++)
		for (int start = 1; start <= n - targetLen + 1; start++)
			sum[start][start + targetLen - 1] = sum[start][start + targetLen - 2] + a[start + targetLen - 1];


	for (int gap = 1; gap <= n - 1; gap++)
	{
		for (int start = 1; start + gap <= n; start++)
		{
			int t1 = a[start] + dp[start+1][start + gap][1];
			int t2 = dp[start][start + gap - 1][1] + a[start + gap];
			dp[start][start + gap][0] = max(t1, t2);
			dp[start][start + gap][1] = sum[start][start + gap] - dp[start][start + gap][0];
		}
	}

	cout << dp[1][n][0] << " " << dp[1][n][1] << endl;

	return 0;
}

