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

const int N = 10;
int n, x, y, z;
char cube[N][N][N];
char view[6][N][N];//前，左，后，右，上，下

char get_symbol()
{
	char c;
	for (;;)
	{
		c = getchar();
		if ((c >= 'A' && c <= 'Z') || c == '.')
			return c;
	}
}

void calc_coordinate(int k, int i, int j, int w)
{
	switch (k)
	{
	case 0:
		x = j;
		y = w;
		z = n - 1 - i;
		break;
	case 1:
		x = w;
		y = n - 1 - j;
		z = n - 1 - i;
		break;
	case 2:
		x = n - 1 - j;
		y = n - 1 - w;
		z = n - 1 - i;
		break;
	case 3:
		x = n - 1 - w;
		y = j;
		z = n - 1 - i;
		break;
	case 4:
		x = j;
		y = n - 1 - i;
		z = n - 1 - w;
		break;
	case 5:
		x = j;
		y = i;
		z = w;
		break;
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	while (scanf("%d", &n) == 1 && n)
	{
		//Input
		for (int i = 0; i < n; i++)
			for (int k = 0; k < 6; k++)
				for (int j = 0; j < n; j++)
					view[k][i][j] = get_symbol();

		memset(cube, '#', N*N*N);

		//去掉视线能贯穿的立方体
		for (int k = 0; k < 6; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (view[k][i][j] == '.')
						for (int w = 0; w < n; w++)
						{
							calc_coordinate(k, i, j, w);
							cube[x][y][z] = '.';
						}

		//去掉不符合视图描述的立方体
		for (;;)
		{
			bool finish = true;
			for (int k = 0; k < 6; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (view[k][i][j] != '.')
							for (int w = 0; w < n; w++)
							{
								calc_coordinate(k, i, j, w);
								if (cube[x][y][z] == '.')
									continue;
								else if (cube[x][y][z] == '#')
								{
									cube[x][y][z] = view[k][i][j];
									break;
								}
								else if (cube[x][y][z] == view[k][i][j])
									break;
								else
								{
									cube[x][y][z] = '.';
									finish = false;
								}
							}

			if (finish)
				break;
		}

		//Result
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					if (cube[i][j][k] != '.')
						++ans;

		printf("Maximum weight: %d gram(s)\n", ans);
	}

	return 0;
}
