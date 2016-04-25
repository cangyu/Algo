/*
ID: yhcy1991
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k;
long long f[205][105] = { 0 };

inline int getMinLevel(int k) { return ceil(log2(k + 1)); }
inline int getMaxLevel(int k) { return (k + 1) / 2; }

int main(int argc, char **argv)
{
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);

	cin >> n >> k;
	f[1][1] = 1;

	for (int i = 3; i <= n; i += 2)
	{
		int minLevel = getMinLevel(i), maxLevel = getMaxLevel(i);

		for (int j = minLevel; j <= maxLevel; j++)
		{
			for (int left = 1; left <= (i - 1)/2; left+=2)
			{
				int right = i - 1 - left;
				if (right % 2 == 0)
					continue;

				int leftMinLevel = getMinLevel(left), leftMaxLevel = getMaxLevel(left);
				int rightMinLevel = getMinLevel(right), rightMaxLevel = getMaxLevel(right);

				for (int p = leftMinLevel; p <= leftMaxLevel; p++)
				{
					for (int q = rightMinLevel; q <= rightMaxLevel; q++)
					{
						if ((p < j - 1 && q < j - 1) || (p > j - 1 || q > j - 1))//不能全小于，也不能有大于的
							continue;
						else
						{
							if (left != right)
								f[i][j] += f[left][p] * f[right][q] * 2;
							else
								f[i][j] += f[left][p] * f[right][q];

							f[i][j] %= 9901;
						}
					}
				}
			}
		}
	}

	cout << f[n][k] << endl;

	return 0;
}
