#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100 + 5;

struct Point
{
	int x, y;

	bool operator<(const Point &rhs) const
	{
		return x < rhs.x;
	}
};

Point pts[N];
int n;
int h[N], left_cnt[N], on[N], on2[N];

int solve(void);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int case_cnt = 0;
	while (cin >> n && n!=0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> pts[i].x >> pts[i].y;
			h[i] = pts[i].y;
		}

		cout <<"Case "<< ++case_cnt << ": "<< solve() << endl;//还有没考虑到的地方？？？？
	}
	return 0;
}

int solve(void)
{
	sort(pts, pts + n);
	sort(h, h + n);
	
	int m = unique(h, h + n) - h;//唯一的高度的数量
	if (m <= 2)
		return n;

	int ans = 0;
	for (int a = 0; a < m; ++a)
	{
		for (int b = a + 1; b < m; ++b)
		{
			const int h_min = h[a], h_max = h[b];
			int line_index = -1, prev_index = -1;
			for (int i = 0; i < n; i++)
			{
				if (pts[i].y >= h_min && pts[i].y <= h_max)
				{
					if (prev_index == -1 || pts[i].x != pts[prev_index].x)
					{
						++line_index;
						on[line_index] = on2[line_index] = 0;
					}

					++on2[line_index];
					if (pts[i].y > h_min && pts[i].y < h_max)
						++on[line_index];

					prev_index = i;
				}
			}

			left_cnt[0] = 0;
			for (int line = 1; line <= line_index; ++line)
				left_cnt[line] = left_cnt[line - 1] + on2[line - 1] - on[line - 1];

			int tmp = 0;
			for (int line = 0; line <= line_index; ++line)
			{
				ans = max(ans, left_cnt[line] + on2[line] + tmp);
				tmp = max(tmp, on[line] - left_cnt[line]);
			}
		}
	}
	return ans;
}
