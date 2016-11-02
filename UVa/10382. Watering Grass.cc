#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 10000 + 5;

struct gap
{
	double xl, xr;

	bool operator<(const gap &rhs) const
	{
		return xl < rhs.xl;
	}
};

gap g[N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n, l, w;
	while (cin >> n >> l >> w)
	{
		int gap_cnt = 0;

		for (int i = 0; i < n; i++)
		{
			int p, r;
			cin >> p >> r;

			if (2 * r <= w)
				continue;

			g[gap_cnt].xl = p*1.0 - sqrt(pow(r, 2) - 0.25*pow(w, 2));
			g[gap_cnt].xr = p*1.0 + sqrt(pow(r, 2) - 0.25*pow(w, 2));
			++gap_cnt;
		}

		sort(g, g + gap_cnt);

		double left = 0.0, right = l*1.0;
		int cnt = 0, cur = 0;
		while (left < right && cur < gap_cnt)
		{
			if (g[cur].xl > left)
				break;

			int longest_index = cur;
			double longest = g[cur].xr - left;
			while (++cur < gap_cnt && g[cur].xl <= left)
			{
				double len = g[cur].xr - left;
				if (len > longest)
				{
					longest = len;
					longest_index = cur;
				}
			}

			++cnt;
			left = g[longest_index].xr;
		}

		cout << (left >= right ? cnt : -1) << endl;
	}

	return 0;
}