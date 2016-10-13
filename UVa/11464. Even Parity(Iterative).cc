#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cstring>

using namespace std;

const int N = 16;
const int di[4] = { 0,-1,0,1 };
const int dj[4] = { -1,0,1,0 };
int T, n;
int mat1[N][N], mat2[N][N];

int calc_toggle(void);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	cin >> T;
	for (int k = 0; k < T; ++k)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> mat1[i][j];

		const int total = 1 << n;
		int ans = -1;
		for (int target = 0; target < total; ++target)
		{
			//Test target
			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				if (target & (1 << i))
					mat2[0][i] = 1;
				else if (mat1[0][i] == 1)
				{
					ok = false;
					break;
				}
				else
					mat2[0][i] = 0;
			}
			if (!ok)
				continue;

			//Calculate the remaining part of mat2
			memcpy(mat2[1], mat1[1], sizeof(int)*(N - 1)*N);
			int curAns = calc_toggle();
			if (curAns == -1)
				continue;
			else if (ans == -1)
				ans = curAns;
			else if (curAns < ans)
				ans = curAns;
		}
		cout << "Case " << k + 1 << ": " << ans << endl;
	}
	return 0;
}

int calc_toggle(void)
{
	//递推计算剩余的行
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			for (int k = 0; k < 3; k++)
			{
				int ci = i - 1 + di[k];
				int cj = j + dj[k];

				if (ci >= 0 && ci < n && cj >= 0 && cj < n)
					sum += mat2[ci][cj];
			}

			if (sum % 2 == 0 && mat2[i][j] == 1)
				return -1;
			else if (sum % 2 != 0 && mat2[i][j] == 0)
				mat2[i][j] = 1;
		}

	//统计
	int toggle_cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mat2[i][j] != mat1[i][j])
				++toggle_cnt;

	return toggle_cnt;
}
