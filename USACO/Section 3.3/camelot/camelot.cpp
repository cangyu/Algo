/*
ID: yhcy1991
PROG: camelot
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
const int dy[8] = { -1,-2,-2,-1,1,2,2,1 };

int king_x = 0, king_y = 0;
int knight_x[800] = { 0 }, knight_y[800] = { 0 };
int cnt_knight = 0;
int R = 0, C = 0;

int dist[31][27][31][27] = { 0 };

void bfs(int i, int j);

int main(int argc, char **argv)
{
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);

	cin >> R >> C;
	char tmp;
	cin >> tmp >> king_x;
	king_y = tmp - ('A' - 1);

	while (cin >> tmp >> knight_x[cnt_knight])
	{
		knight_y[cnt_knight] = tmp - ('A' - 1);
		cnt_knight++;
	}

	if (cnt_knight == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			for (int n = 1; n <= R; n++)
				for (int m = 1; m <= C; m++)
					dist[i][j][n][m] = -1;

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			bfs(i, j);

	int min_move = 2147483647;

	//枚举每一个点作为ending point
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			//King自己过去
			int king_move = max(abs(king_x - i), abs(king_y - j));
			int all_knight_move = 0;
			bool all_can_reach = true;
			for (int k = 0; k < cnt_knight; k++)
			{
				if (dist[knight_x[k]][knight_y[k]][i][j] == -1)
				{
					all_can_reach = false;
					break;
				}
				all_knight_move += dist[knight_x[k]][knight_y[k]][i][j];
			}
			if (!all_can_reach)
				continue;

			int ans = king_move + all_knight_move;
			min_move = min(min_move, ans);

			//取King周围半径为2的所有点作为meeting point,由knight带着king过去
			for (int dmx = -2; dmx <= 2; dmx++)
			{
				for (int dmy = -2; dmy <= 2; dmy++)
				{
					int mx = king_x + dmx;
					int my = king_y + dmy;

					if (mx<1 || mx>R || my<1 || my>C)
						continue;

					if (mx == i && my == j)
						continue;

					for (int k = 0; k < cnt_knight; k++)
					{
						if (dist[knight_x[k]][knight_y[k]][mx][my] == -1 || dist[mx][my][i][j] == -1)
							continue;

						int left_knight_move = all_knight_move - dist[knight_x[k]][knight_y[k]][i][j];
						if (left_knight_move > min_move)
							continue;

						int move1 = dist[knight_x[k]][knight_y[k]][mx][my];
						int move2 = max(abs(king_x - mx), abs(king_y - my));
						int move3 = dist[mx][my][i][j];

						ans = move1 + move2 + move3 + left_knight_move;
						min_move = min(min_move, ans);

					}
				}
			}
		}
	}

	cout << min_move << endl;

	return 0;
}

/* 计算从（i,j）出发到所有能到达的点的距离 */
void bfs(int i, int j)
{
	dist[i][j][i][j] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		int curMove = dist[i][j][curX][curY];
		for (int dir = 0; dir < 8; dir++)
		{
			int nextX = curX + dx[dir];
			int nextY = curY + dy[dir];

			if (nextX<1 || nextX>R || nextY<1 || nextY>C)
				continue;

			if (dist[i][j][nextX][nextY] != -1)
				continue;
			else
			{
				dist[i][j][nextX][nextY] = curMove + 1;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
}

