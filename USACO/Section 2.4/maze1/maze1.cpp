/*
ID: yhcy1991
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct point
{
	int x, y;
	bool hasWall[4];
	int step[2];
	bool hasVisited;
	point() :x(-1), y(-1), hasVisited(false) 
	{
		fill_n(hasWall, 4, false); 
		fill_n(step, 2, 0);
	}
};

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int w = 0, h = 0;
int maze[205][80] = { 0 };//注意行列顺序！！！
point map[105][40];
int out_pos[2][2] = { 0 };

void bfs(int x, int y, int round);

int main(int argc, char **argv)
{
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);

	cin >> w >> h;
	memset(maze, 0, sizeof(maze));
	memset(out_pos, 0, sizeof(out_pos));
	const int n = 2 * h + 1, m = 2 * w + 1;
	int out_cnt = 0;

	/* Input the maze */
	char c = getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((c = getchar()) != ' ')
				maze[i][j] = -1;

			if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && maze[i][j] == 0)
			{
				maze[i][j] = 1;
				out_pos[out_cnt][0] = i;
				out_pos[out_cnt][1] = j;
				out_cnt++;
			}
		}
		c = getchar();
	}

	/* Construct the map */
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			map[i][j].x = i;
			map[i][j].y = j;
			int mi = 2 * i - 1, mj = 2 * j - 1;
			for (int d = 0; d < 4; d++)
			{
				int x = mi + dx[d], y = mj + dy[d];
				if (maze[x][y] == -1)
					*(map[i][j].hasWall + d) = true;
			}
		}
	}

	/* BFS */
	for (int i = 0; i < 2; i++)
	{
		for (int u = 1; u <= h; u++)
			for (int v = 1; v <= w; v++)
				map[u][v].hasVisited = false;

		int startX = max((out_pos[i][0] + 1) / 2, 1);//在上边界有出口时，转换后的x坐标至少要为1
		int startY = max((out_pos[i][1] + 1) / 2, 1);//在左边界有出口时，转换后的y坐标至少要为1

		bfs(startX, startY, i);
	}

	/* Output */
	int res = 0;
	for (int u = 1; u <= h; u++)
		for (int v = 1; v <= w; v++)
			res = max(res, min(map[u][v].step[0], map[u][v].step[1]));

	cout << res << endl;
	return 0;
}

void bfs(int x, int y, int round)
{
	map[x][y].step[round] = 1;
	map[x][y].hasVisited = true;

	queue<point> q;
	q.push(map[x][y]);
	while (!q.empty())
	{
		point t = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			if (map[t.x][t.y].hasWall[dir])
				continue;

			int nextX = t.x + dx[dir];
			int nextY = t.y + dy[dir];

			if (nextX < 0 || nextX > h || nextY < 0 || nextY > w || map[nextX][nextY].hasVisited)
				continue;

			map[nextX][nextY].hasVisited = true;
			map[nextX][nextY].step[round] = t.step[round] + 1;
			q.push(map[nextX][nextY]);
		}
	}
}
