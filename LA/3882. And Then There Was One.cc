#include <iostream>

using namespace std;

const int N = 10000 + 5;

int n, k, m;
int f[N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	f[1] = 0;
	while (cin >> n >> k >> m && n)
	{
		for (int i = 2; i < n; i++)
			f[i] = (f[i - 1] + k) % i;

		int ans = (m + f[n - 1]) % n;//注意原题中序号范围是是1_n，这里以0_n-1来进行取余

		cout << ans + 1 << endl;
	}

	return 0;
}