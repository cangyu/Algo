#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

const int N = 16;
const int di[4] = { 0,-1,0,1 };
const int dj[4] = { -1,0,1,0 };
int T, n;
int mat1[N][N], mat2[N][N];

int check(int w, int cnt);
int count(int cur);

int main(int argc, char **argv)
{
	cin >> T;
	for (int k = 0; k < T; ++k)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> mat1[i][j];

		cout << check(0, 0) << endl;
	}
	return 0;
}

int check(int w, int cnt)
{
	while (w < n && mat1[0][w] == 1)
		++w;

	if (w < n)
	{
		int ans1 = check(w + 1, cnt);
		mat1[0][w] = 1;
		int ans2 = check(w + 1, cnt + 1);
		mat1[0][w] = 0;//注意要复原，给后面的过程再使用
		
		if (ans1 == -1)
			return ans2;
		else if (ans2 == -1)
			return ans1;
		else
			return min(ans1, ans2);
	}
	else
		return count(cnt);
}

int count(int cur)
{
	memcpy(mat2, mat1, sizeof(mat1));
	for(int i=0;i<n-1;i++)
		for (int j = 0; j < n; j++)
		{
			int ti = i + di[3], tj = j + dj[3];
			int sum = 0;

			for (int k = 0; k < 4; k++)
			{
				int ci = i + di[k], cj = j + dj[k];
				if (ci >= 0 && ci < n && cj >= 0 && cj < n)
					sum += mat2[ci][cj];
			}

			if (sum % 2 != 0)
			{
				if (mat2[ti][tj] == 0)
				{
					mat2[ti][tj] = 1;
					++cur;
				}
				else
					return -1;
			}
		}

	return cur;
}
