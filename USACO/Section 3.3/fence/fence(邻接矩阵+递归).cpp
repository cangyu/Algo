/*
ID: yhcy1991
PROG: fence
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int m[502][502];
int degree[502];
int circuit[1030];
int f = 0, cnt = 0;
int verMax = 0;

void eulerCircuit(int start);

int main(int argc, char **argv)
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	memset(m, 0, sizeof(m));
	memset(degree, 0, sizeof(degree));
	memset(circuit, 0, sizeof(circuit));

	cin >> f;
	for (int i = 0; i < f; i++)
	{
		int a, b;
		cin >> a >> b;
		m[a][b]++;
		m[b][a]++;
		degree[a]++;
		degree[b]++;
		verMax = max(verMax, max(a, b));
	}

	int start = 1;
	for (int i = 1; i <= verMax; i++)
	{
		if (degree[i] % 2 == 1)
		{
			start = i;
			break;
		}
	}

	eulerCircuit(start);

	for (int i = cnt - 1; i >= 0; i--)
		cout << circuit[i] << endl;

	return 0;
}

void eulerCircuit(int start)
{
	for (int i = 1; i <= verMax; i++)
	{
		if (m[start][i] != 0)
		{
			m[start][i]--;
			m[i][start]--;
			eulerCircuit(i);
		}
	}

	circuit[cnt++] = start;
}
