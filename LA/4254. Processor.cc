#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int N = 10000;

struct Task
{
	int r, d, w;

	bool operator<(const Task &rhs) const
	{
		return d > rhs.d;
	}
};

Task t[N];
int n;

bool check(int s);
bool mycmp(const Task &lhs, const Task &rhs);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> t[i].r >> t[i].d >> t[i].w;

		sort(t, t + n, mycmp);
		
		int s_min = 1, s_max = 10000000;
		while (s_min < s_max)
		{
			int s = (s_min + s_max) / 2;
			if (check(s))
				s_max = s;
			else
				s_min = s + 1;
		}

		cout << s_max << endl;
	}

	return 0;
}

bool check(int s)
{
	priority_queue<Task> pq;
	int i = 0;
	for (int cur = 1; cur < 20000; ++cur)
	{
		while (i < n && t[i].r <= cur)
			pq.push(t[i++]);

		int seg_cnt = s;
		while(seg_cnt && !pq.empty())
		{
			Task ct = pq.top();
			pq.pop();

			if (ct.d <= cur)
				return false;

			if (seg_cnt >= ct.w)
				seg_cnt -= ct.w;
			else
			{
				ct.w -= seg_cnt;
				seg_cnt = 0;
				pq.push(ct);
			}
		}

		if (i == n && pq.empty())
			return true;
	}

	return false;
}

bool mycmp(const Task &lhs, const Task &rhs)
{
	return lhs.r < rhs.r;
}