/*
ID: yhcy1991
PROG: agrinet
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n;
int adjm[105][105] = { 0 };
bool hasTaken[105];
int lowCost[105];
const int notExist = 200000;

int main(int argc, char **argv)//��Prim�㷨��ÿ���ȸ��£�������֮��������С�ģ�Ҳ������krustal�������ȶ��д�ߣ���ϲ��鼯����������������ݽ��ʺ�prim
{
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);

	memset(adjm, 0, sizeof(adjm));
	fill_n(hasTaken, sizeof(hasTaken) / sizeof(bool), false);
	fill_n(lowCost, sizeof(lowCost) / sizeof(int), notExist);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adjm[i][j];

	for (int i = 1; i <= n; i++)
		adjm[i][i] = notExist;

	int ans = 0;
	int start = 1;

	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i <= n; i++)
			if (!hasTaken[i])
				lowCost[i] = min(lowCost[i], adjm[start][i]);

		hasTaken[start] = true;

		int minWeight = notExist;
		for (int i = 1; i <= n; i++)
		{
			if (!hasTaken[i] && lowCost[i] < minWeight)
			{
				minWeight = lowCost[i];
				start = i;
			}
		}
		
		ans += minWeight;
	}

	cout << ans << endl;
	return 0;
}
