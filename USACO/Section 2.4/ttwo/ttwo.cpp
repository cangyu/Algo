/*
ID: yhcy1991
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int m[10][10] = { 0 };
int q[10][10][4][10][10][4] = { 0 };
int t = 0;
int xc, yc, dc, xf, yf, df;

void move(int &x, int &y, int &d);

int main(int argc, char **argv)
{
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);

	memset(m, sizeof(m), 0);
	memset(q, sizeof(q), 0);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			char c;
			cin >> c;
			if (c == '*')
				m[i][j] = 1;
			else if (c == 'F')
				xf = i, yf = j, df = 0;
			else if (c == 'C')
				xc = i, yc = j, dc = 0;
			else
				continue;
		}
	}
	while (true)
	{
		if (q[xf][yf][df][xc][yc][dc])
		{
			cout << 0 << endl;
			break;
		}
		q[xf][yf][df][xc][yc][dc] = 1;
		if (xf == xc && yf == yc)
		{
			cout << t << endl;
			break;
		}
		t++;
		move(xf, yf, df);
		move(xc, yc, dc);
	}

	return 0;
}

void move(int &x, int &y, int &d)
{
	int nextX = x + dx[d];
	int nextY = y + dy[d];	
	if (nextX < 0 || nextX > 9 || nextY < 0 || nextY > 9 || m[nextX][nextY] != 0)
		d = (d + 1) % 4;
	else
	{
		x = nextX;
		y = nextY;
	}
}