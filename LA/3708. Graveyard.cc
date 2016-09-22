#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

int main(int argc, char **argv)
{
	int n = 0, m = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		double ans = 0;
		for (int i = 1; i < n; i++)
		{
			if (i*(n + m) % n == 0)
				continue;

			double pos = (double)(n + m) / n*i;
			ans += fabs(pos - floor(pos + 0.5)) / (n + m);//快速取得距离最近端点的距离
		}
		printf("%.4lf\n", ans * 10000);
	}
	return 0;
}
