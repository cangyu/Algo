#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000 + 5;

int n, S;
int sum[N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	while (cin >> n >> S)
	{
		sum[0] = 0;
		int a = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a;
			sum[i] = sum[i - 1] + a;
		}

		int ans = n + 1;
		int start = 1, finish = 1;
		for (; finish <= n; ++finish)
		{
			if (sum[finish] - sum[start - 1] < S)
				continue;

			while (sum[finish] - sum[start] >= S)
				++start;

			ans = min(ans, finish - start + 1);
		}

		cout << (ans == n + 1 ? 0 : ans) << endl;
	}

	return 0;
}