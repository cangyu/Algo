#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100 + 5;

int n;
int S[N], dp[N][N];
bool visited[N][N];

int calc_dp(int i, int j);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	S[0] = 0;

	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> S[i];
			S[i] += S[i - 1];
		}

		memset(visited, 0, sizeof(visited));

		cout << 2 * calc_dp(1, n) - S[n] << endl;
	}

	return 0;
}

int calc_dp(int i, int j)
{
	if (visited[i][j])
		return dp[i][j];

	int m = 0;
	for (int left = i + 1; left <= j; ++left)
		m = min(m, calc_dp(left, j));
	for (int right = j - 1; right >= i; --right)
		m = min(m, calc_dp(i, right));

	visited[i][j] = true;
	return dp[i][j] = S[j] - S[i - 1] - m;
}