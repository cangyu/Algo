/*
ID: yhcy1991
PROG: milk6
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long s64;

s64 n, m;

struct edge
{
	s64 x, y;
	s64 f;
	edge() :x(0), y(0), f(0) {}
};

edge e[2004];
s64 c[40][40] = { 0 };
s64 cc[40][40] = { 0 };

class netflow
{
private:
	s64 h[100], vh[100];//高度
	s64 ans, flow;
	bool found;

	void aug(int x)
	{
		if (x == n)
		{
			found = true;
			ans += flow;
			return;
		}
		s64 minh = n - 1, old = flow, i;
		for (i = 1; i <= n; i++)
		{
			if (cc[x][i] > 0)
			{
				if (h[i] + 1 == h[x])//只相差一个高度
				{
					flow = min(flow, cc[x][i]);
					aug(i);
					if (h[1] > n)
						return;
					if (found)
						break;
				}
				minh = min(minh, h[i]);
			}
		}
		if (found)
		{
			cc[x][i] -= flow;
			cc[i][x] += flow;
		}
		else
		{
			vh[h[x]]--;
			if (vh[h[x]] == 0)
				h[1] = n;
			h[x] = minh + 1;
			vh[h[x]]++;
		}
	}

public:
	s64 maxflow()//推送-重贴标签方法，不同于Section 4.2中写的那个基于bfs找增广路的krap
	{
		memset(h, 0, sizeof(h));
		memset(vh, 0, sizeof(vh));
		h[0] = n;
		ans = 0;
		while (h[1] < n)
		{
			flow = 4294967295;
			found = false;
			aug(1);
		}
		return ans;
	}
};

netflow zuidaliu;
s64 ans[2004] = { 0 };

int main(int argc, char** argv)
{
	freopen("milk6.in", "r", stdin);
	freopen("milk6.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].x >> e[i].y >> e[i].f;
		e[i].f = e[i].f * 1001 + 1;
		c[e[i].x][e[i].y] += e[i].f;//有可能有重复边，要累加
	}

	memcpy(cc, c, sizeof(cc));
	s64 mf = zuidaliu.maxflow();
	cout << mf / 1001 << ' ' << mf % 1001 << endl;

	for (int i = 1; i <= m; i++)
	{
		if (mf == 0)
			break;
		
		memcpy(cc, c, sizeof(cc));
		cc[e[i].x][e[i].y] -= e[i].f;
		s64 curf = zuidaliu.maxflow();
		if (curf + e[i].f == mf)
		{
			mf -= e[i].f;
			c[e[i].x][e[i].y] -= e[i].f;
			ans[++ans[0]] = i;
		}
	}

	for (int i = 1; i <= ans[0]; i++)
		cout << ans[i] << endl;

	return 0;
}
