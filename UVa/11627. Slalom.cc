#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N1 = 1e5 + 50;
const int N2 = 1e6 + 50;

int x[N1], y[N1], s[N2];
int w, vh, n;

bool check(int speed);

int main(int argc, char **argv)//没过官方测试，貌似有毒
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> w >> vh >> n;
		for (int i = 1; i <= n; i++)
			cin >> x[i] >> y[i];

		int S;
		cin >> S;
		memset(s, 0, sizeof(s));
		int cnt = 0;
		for (int i = 0; i < S; i++)
		{
			int speed;
			cin >> speed;
			if (!s[speed])
			{
				s[speed] = 1;
				++cnt;
			}
		}

		vector<int> huaban(cnt, 0);
		for (int i = 1, j = 0; i <= (int)(1e6); i++)
		{
			if (s[i])
				huaban[j++] = i;
		}

		if (!check(huaban[0]))
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		int sl = 0, sr = cnt - 1;
		while (sl < sr)
		{
			int si = (sl + sr + 1) / 2;
			if (check(huaban[si]))
				sl = si;
			else
				sr = si - 1;
		}

		cout << huaban[sl] << endl;
	}

	return 0;
}

bool check(int speed)
{
	double cl = (double)x[1], cr = (double)(x[1] + w);
	const double factor = ((double)vh) / ((double)speed);
	for (int i = 1; i <= n - 1; i++)
	{
		double span = (double)(y[i + 1] - y[i])*factor;
		cl -= span;
		cr += span;

		cl = max(cl, (double)x[i + 1]);
		cr = min(cr, (double)(x[i + 1] + w));
		if (cl > cr)//nice
			return false;
	}

	return true;
}