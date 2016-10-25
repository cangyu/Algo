#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100 + 5;

int n;
int s[N], d[N][N], f[N][N], g[N][N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	s[0] = 0;

	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			d[i][i] = f[i][i] = g[i][i] = s[i];
			s[i] += s[i - 1];
		}

		//把递推式拆成两部分
		for (int gap = 1; gap < n; ++gap)
			for (int i = 1; i + gap <= n; i++)
			{
				int j = i + gap;
				int m = 0;
				m = min(m, f[i + 1][j]);
				m = min(m, g[i][j - 1]);
				
				d[i][j] = s[j] - s[i - 1] - m;//按照gap一个个来算d，再算f、g
				f[i][j] = min(d[i][j], f[i + 1][j]);
				g[i][j] = min(d[i][j], g[i][j - 1]);
			}

		cout << 2 * d[1][n] - s[n] << endl;
	}

	return 0;
}
