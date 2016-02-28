/*
ID: yhcy1991
PROG: wormhole
LANG: C++
*/

//用递归来实现多层循环
//有回路的检测

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &pair, const vector<int> &nextRef);
bool hasCycle(int n, const vector<int> &pair, const vector<int> &nextRef);

typedef struct point {
	int x;
	int y;
	point(int a = 0, int b = 0) :x(a), y(b){}
}PointTypeDef;

int main()
{
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");

	int n;
	fin >> n;
	vector<PointTypeDef> wormholes(n + 1);
	for (int i = 1; i <= n; i++)
		fin >> wormholes[i].x >> wormholes[i].y;

	vector<int> nextOnRight(n + 1, 0);
	vector<int> partner(n + 1, 0);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (wormholes[j].y == wormholes[i].y && wormholes[j].x > wormholes[i].x)
			{
				if (nextOnRight[i] == 0 || wormholes[j].x < wormholes[nextOnRight[i]].x)//初始情况的归一化处理
					nextOnRight[i] = j;
			}
		}
	}

	int ans = solve(n, partner, nextOnRight);

	fout << ans << endl;

	fin.close();
	fout.close();
	return 0;
}

int solve(int n, vector<int> &pair, const vector<int> &nextRef)
{
	int sum = 0, i;
	for (i = 1; i <= n; i++)
	{
		if (pair[i] == 0)
			break;
	}

	if (i > n)
	{
		if (hasCycle(n, pair, nextRef))
			return 1;
		else
			return 0;
	}

	for (int j = i + 1; j <= n; j++)
	{
		if (pair[j] == 0)
		{
			pair[i] = j, pair[j] = i;
			sum += solve(n, pair, nextRef);
			pair[i] = pair[j] = 0;
		}
	}
	return sum;
}

bool hasCycle(int n, const vector<int> &pair, const vector<int> &nextRef)
{
	for (int start = 1; start <= n; start++)
	{
		int pos = start;
		for (int i = 0; i < n; i++)
			pos = nextRef[pair[pos]];//Start directly from the dangerous place
		if (pos != 0)
			return true;
	}
	return false;
}