/*
ID: yhcy1991
PROG: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <algorithm>


using namespace std;

int dist[128] = { 0 };
bool known[128];
int adjm[128][128];
int p = 0;
char *cand = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

const int notExist = 2147483647 / 2;

int main(int argc, char **argv)
{
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);

	fill_n(dist, 128, notExist);
	fill_n(known, 128, false);
	for (int i = 0; i < 128; i++)
		fill_n(adjm[i], 128, notExist);

	cin >> p;
	char a, b;
	int len;
	for (int i = 0; i < p; i++)
	{
		cin >> a >> b >> len;
		adjm[a][b] = min(adjm[a][b], len);//有可能有重复元素，要取最小
		adjm[b][a] = min(adjm[b][a], len);
	}

	dist['Z'] = 0;

	bool finish = false;
	while (!finish)
	{
		char minch;
		int minWeight = notExist;

		finish = true;
		for (char *p=cand; *p; p++)
		{
			if (!known[*p] && dist[*p] < minWeight)
			{
					minch = *p;
					minWeight = dist[*p];
					finish = false;
			}
		}
		if (finish)
			break;

		known[minch] = true;

		for (char *p = cand; *p; p++)
		{
			if (!known[*p])
				dist[*p] = min(dist[*p], dist[minch] + adjm[minch][*p]);
		}
	}

	int shortestLen = notExist;
	char start = 'Z';
	for (int i = 'A'; i < 'Z'; i++)
	{
		if (dist[i] < shortestLen)
		{
			shortestLen = dist[i];
			start = i;
		}
	}

	cout << start << ' ' << shortestLen << endl;

	return 0;
}