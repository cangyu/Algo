#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

const int N = 20 + 5;
long long v[N][N][N];

long long summation(const int &x1, const int &x2, const int &y1, const int &y2, const int &z);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	memset(v, 0, sizeof(v));
	
	while (T--)
	{
		int A, B, C;
		cin >> A >> B >> C;
		for (int i = 1; i <= A; i++)
			for (int j = 1; j <= B; j++)
				for (int k = 1; k <= C; k++)
				{
					cin >> v[i][j][k];
					v[i][j][k] += (v[i][j - 1][k] + v[i][j][k - 1] - v[i][j - 1][k - 1]);//Accumulate in 2D
				}

		for (int j = 1; j <= B; j++)
			for (int k = 1; k <= C; k++)
				for (int i = 1; i <= A; i++)
					v[i][j][k] += v[i - 1][j][k];//Accumulate in 3D

		long long ans = (numeric_limits<long long>::min)();
		for (int x1 = 1; x1 <= A; ++x1)
			for (int x2 = x1; x2 <= A; ++x2)
				for (int y1 = 1; y1 <= B; ++y1)
					for (int y2 = y1; y2 <= B; ++y2)
					{
						long long down = 0;
						for (int z = 1; z <= C; ++z)
						{
							long long s = summation(x1, x2, y1, y2, z);
							ans = max(ans, s - down);
							down = min(down, s);
						}
					}

		cout << ans << endl;
		if (T)
			cout << endl;
	}

	return 0;
}

inline long long summation(const int &x1, const int &x2, const int &y1, const int &y2, const int &z)
{
	return v[x2][y2][z] + v[x1 - 1][y1 - 1][z] - v[x1 - 1][y2][z] - v[x2][y1 - 1][z];
}
