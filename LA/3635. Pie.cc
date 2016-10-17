#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

inline bool check(double _a);

const int N = 10000 + 5;
const double PI = acos(-1.0);

double area[N];
int n, f;

int main(int argc, char **argv)
{
	int T = 0;
	cin >> T;

	while (T--)
	{
		cin >> n >> f;

		double area_min = 0, area_max = -1.0;
		for (int i = 0; i < n; i++)
		{
			int r;
			cin >> r;
			area[i] = PI*r*r;
			area_max = max(area_max, area[i]);
		}

		while (abs(area_max - area_min) > 1e-5)
		{
			double _area = (area_min + area_max) / 2;
			if (check(_area))
				area_min = _area;
			else
				area_max = _area;
		}
		cout <<fixed << setprecision(4) << area_min << endl;
	}

	return 0;
}

inline bool check(double _a)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (int)floor(area[i] / _a);

	return cnt >= f + 1;
}