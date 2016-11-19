#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int N=5000+5;

struct frame
{
	int index;
	int L, R;
	int pos;
};

int n;
frame x[N], y[N];

bool cmp0(const frame &lhs, const frame &rhs);
bool cmp1(const frame &lhs, const frame &rhs);
bool solve(frame *f);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			x[i].index = y[i].index = i;
			cin >> x[i].L >> y[i].L >> x[i].R >> y[i].R;
		}

		sort(x, x + n, cmp0);
		sort(y, y + n, cmp0);

		if (solve(x) && solve(y))
		{
			sort(x, x + n, cmp1);
			sort(y, y + n, cmp1);

			for (int i = 0; i < n; i++)
				cout << x[i].pos << ' ' << y[i].pos << endl;
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}

bool cmp0(const frame &lhs, const frame &rhs)
{
	return lhs.L < rhs.L;
}

bool cmp1(const frame &lhs, const frame &rhs)
{
	return lhs.index < rhs.index;
}

struct cmp2 
{
	bool operator()(frame* lhs, frame* rhs)
	{
		return lhs->R > rhs->R;
	}
};

bool solve(frame *f)
{
	int ct = 1, ci = 0;
	priority_queue<frame*, vector<frame*>, cmp2> pq;

	while (ct <= n)
	{
		while (ci < n && f[ci].L <= ct)
			pq.push(f + ci++);

		if (pq.empty() || pq.top()->R < ct)
			return false;

		pq.top()->pos = ct;
		pq.pop();
		++ct;
	}

	return true;
}
