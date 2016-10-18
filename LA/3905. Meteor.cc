#include <iostream>
#include <algorithm>

using namespace std;

struct Event
{
	int t;
	int type;

	Event(int _t = 0, int _type = 0) :t(_t), type(_type) {}

	bool operator<(const Event &rhs) const
	{
		return t < rhs.t || (t == rhs.t && type > rhs.type);//要先减掉离开的事件
	}
};

const int N = 100000 + 5;

int n, w, h;
int gap_cnt;
Event e[N * 2];//进入和离开是一对

void update_gap(const int &px, const int &py, const int &vx, const int &vy);
void calc_gap(const int &p, const int &v, const int &l, int &start, int &finish);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> w >> h >> n;
		gap_cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y, a, b;
			cin >> x >> y >> a >> b;
			update_gap(x, y, a, b);
		}

		sort(e, e + gap_cnt);//key part!

		int ans = 0, cnt = 0;
		for (int i = 0; i < gap_cnt; i++)
		{
			if (e[i].type == 0)
				ans = max(ans, ++cnt);
			else
				--cnt;
		}
		
		cout << ans << endl;
	}
	return 0;
}

void update_gap(const int &px, const int &py, const int &vx, const int &vy)
{
	int xt1, xt2, yt1, yt2;
	calc_gap(px, vx, w, xt1, xt2);
	calc_gap(py, vy, h, yt1, yt2);

	int _left = max(xt1, yt1);
	int _right = min(xt2, yt2);

	if (_right > _left)
	{
		new (e + gap_cnt++) Event(_left);
		new (e + gap_cnt++) Event(_right, 1);
	}
}

void calc_gap(const int &p, const int &v, const int &l, int &start, int &finish)
{
	start = finish = 0;
	if (v == 0)
	{
		if (p > 0 && p < l)
			finish = 2147483647;
	}
	else if (v > 0)
	{
		int t1 = -p * 2520 / v;
		int t2 = (l - p) * 2520 / v;
		start = max(0, t1);
		finish = max(0, t2);
	}
	else
	{
		int t1 = (l - p) * 2520 / v;
		int t2 = -p * 2520 / v;
		start = max(0, t1);
		finish = max(0, t2);
	}
}
