#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000 + 5;

char mat[N][N];
int height[N][N], range_left[N][N], range_right[N][N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		//Init and Input
		int m, n;
		cin >> m >> n;
		memset(height, 0, sizeof(height));
		memset(range_left, 0, sizeof(range_left));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				range_right[i][j] = n + 1;

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				cin >> mat[i][j];
				if (mat[i][j] == 'F')
					height[i][j] = height[i - 1][j] + 1;
			}

		//Scan
		int ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int left_obstacle = 0;
			for (int j = 1; j <= n; j++)
				if (mat[i][j] == 'R')
					left_obstacle = j;
				else
					range_left[i][j] = max(left_obstacle + 1, range_left[i - 1][j]);

			int right_obstacle = n + 1;
			for (int j = n; j >= 1; j--)
				if (mat[i][j] == 'R')
					right_obstacle = j;
				else
					range_right[i][j] = min(right_obstacle - 1, range_right[i - 1][j]);

			for (int j = 1; j <= n; j++)
				if (mat[i][j] == 'F')
					ans = max(ans, height[i][j] * (range_right[i][j] - range_left[i][j] + 1));
		}

		//Output
		cout << ans * 3 << endl;
	}
	return 0;
}
