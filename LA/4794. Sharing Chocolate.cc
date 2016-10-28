#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 15;
const int M = 100 + 5;

int a[N], sum[1 << N], dp[1 << N][M];
bool visited[1 << N][M];

int f(int S, int x);
int bit_cnt(int x);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int case_cnt = 0, n;
	while (cin >> n && n)
	{
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		memset(sum, 0, sizeof(sum));
		for (int S = 0; S < (1 << n); ++S)
			for (int i = 0; i < n; i++)
				if (S&(1 << i))
					sum[S] += a[i];

		memset(visited, 0, sizeof(visited));
		const int ALL = (1 << n) - 1;
		int ans = 0;
		if (sum[ALL] == x*y)
			ans = f(ALL, min(x, y));

		cout << "Case " << ++case_cnt << ": " << (ans ? "Yes" : "No") << endl;
	}

	return 0;
}

int f(int S, int x)
{
	if (visited[S][x])
		return dp[S][x];

	visited[S][x] = true;
	int &ans = dp[S][x];

	if (bit_cnt(S) == 1)
		return ans = 1;

	int y = sum[S] / x;
	for (int S0 = (S - 1)&S; S0; S0 = (S0 - 1)&S)//集合来表示
	{
		int S1 = S - S0;
		if (sum[S0] % x == 0 && f(S0, min(x, sum[S0] / x)) && f(S1, min(x, sum[S1] / x)))//从短边整除的角度考虑即可，不必两边全考虑， 程序自己选择
			return ans = 1;
		if (sum[S0] % y == 0 && f(S0, min(y, sum[S0] / y)) && f(S1, min(y, sum[S1] / y)))
			return ans = 1;
	}

	return ans = 0;
}

int bit_cnt(int x)
{
	return x == 0 ? 0 : bit_cnt(x / 2) + (x & 1);
}