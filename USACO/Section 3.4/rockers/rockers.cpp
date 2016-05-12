/*
ID: yhcy1991
PROG: rockers
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int N, T, M;
int cost[21] = { 0 };
int f[21][21][21] = { 0 };

int main(int argc, char **argv) //在前i首歌中选，在前j张CD，且最后一张CD的时长为k，在这一情况下能存放的歌曲数
{
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);

	cin >> N >> T >> M;

	for (int i = 1; i <= N; i++)
		cin >> cost[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <= T; k++)
			{
				if (k < cost[i])
					f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - 1][T]);
				else
					f[i][j][k] = max(f[i - 1][j][k - cost[i]], f[i - 1][j - 1][T]) + 1;
			}
		}
	}

	cout << f[N][M][T] << endl;

	return 0;
}
