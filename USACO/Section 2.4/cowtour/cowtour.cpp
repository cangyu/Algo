/*
ID: yhcy1991
PROG: cowtour
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

struct point
{
	int x;
	int y;
};

point p[155];
double dist[155][155];
double maxDiameter[155];
const double notExist = (1e14);
int n;
int parent[155];

inline double dis(const point &p1, const point &p2);
void Union(int root1, int root2);
int Find(int x);
void floyd();

int main(int argc, char **argv)//用并查集来描述不同的归属，floyd算法计算每个元素中的最短路
{
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
        
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	
	fill_n(parent, n, -1);
	char c = getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c = getchar();
			if (c == '0')
				dist[i][j] = notExist;
			else
			{
				dist[i][j] = dis(p[i], p[j]);
				Union(Find(i), Find(j));
			}
		}
		c = getchar();
	}

	floyd();

	double maxd = 0;
	for (int i = 0; i < n; i++)
	{
		double max_diameter = 0;
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] != notExist)
				max_diameter = max(max_diameter, dist[i][j]);
		}
		maxDiameter[i] = max_diameter;
		maxd = max(maxd, max_diameter);//有可能连接后的集合的diameter比原先两者之一的diameter还要小，这是因为两次diameter的计算方法不同
	}

	double ans = notExist;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (Find(i) != Find(j))
			{
				double bridgeLen = dis(p[i], p[j]);
				ans = min(ans, bridgeLen + maxDiameter[i] + maxDiameter[j]);
			}
		}
	}
	cout << setprecision(6) << fixed << max(ans, maxd) << endl;

	return 0;
}

inline double dis(const point &p1, const point &p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void Union(int root1, int root2)
{
	if (root1 == root2)
		return;
	if (parent[root1] > parent[root2])
	{
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}
	else
	{
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
}

int Find(int x)
{
	if (parent[x] < 0)
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void floyd()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)//虽然已经初始化每个点到自身的距离是notExist，但是在上述算法中会再找回去，因此要重设一遍
		dist[i][i] = notExist;
}


/*

Ref:https://www.byvoid.com/blog/usaco-243-cow-tours
个人觉得最后有问题，如果两个点属于同一个联通分量且未连接，计算出来的结果是有问题的

#include <stdio.h>
#include <math.h>
#define ITF (1e40)

FILE *fi, *fo;
long n;
double dis[200][200], dt[200];
long px[200], py[200];

double dist(long& x1, long& y1, long& x2, long& y2)
{
	return sqrt((double)(x1 - x2)*(x1 - x2) + (double)(y1 - y2)*(y1 - y2));
}

void floyed()
{
	long i, j, k;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (dis[i][k] + dis[k][j]<dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
	for (i = 1; i <= n; i++)
		dis[i][i] = ITF;
}

int main(void)
{
	long i, j, a;
	double pmax, pmin, tmp, max = 0;
	fi = fopen("cowtour.in", "r");
	fo = fopen("cowtour.out", "w");
	fscanf(fi, "%ld", &n);
	for (i = 1; i <= n; i++)
	{
		fscanf(fi, "%ld%ld", &px[i], &py[i]);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			a = 10;
			while (a == 10 || a == 13)
				a = getc(fi);
			a -= 48;
			if (a)
			{
				dis[i][j] = dist(px[i], py[i], px[j], py[j]);
			}
			else
			{
				dis[i][j] = ITF;
			}
		}
	}
	floyed();

	for (i = 1; i <= n; i++)
	{
		pmax = 0;
		for (j = 1; j <= n; j++)
		{
			if (dis[i][j]>pmax && dis[i][j] != ITF)
				pmax = dis[i][j];
		}
		dt[i] = pmax;
		if (pmax>max) max = pmax;
	}
	pmin = ITF;
	for (i = 1; i <= n - 1; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (dis[i][j] == ITF && i != j)
			{
				tmp = dist(px[i], py[i], px[j], py[j]);
				if (dt[i] + dt[j] + tmp<pmin)
					pmin = dt[i] + dt[j] + tmp;
			}
		}
	}

	fprintf(fo, "%.6lf\n", pmin>max ? pmin : max);
	fclose(fi);
	fclose(fo);
	return 0;
}
*/