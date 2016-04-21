/*
ID: yhcy1991
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int V = 0, G = 0;
int min_req[25] = { 0 };
int candidate[15][25] = { 0 };
bool visited[15] = { false };
bool hasFound = false;
int s[25] = { 0 };

void dfs(int start, int remainLen);
bool check();

int main()
{
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	cin >> V;
	for (int i = 0; i < V; i++)
		cin >> min_req[i];
	cin >> G;
	for (int i = 0; i < G; i++)
		for (int j = 0; j < V; j++)
			cin >> candidate[i][j];


	for (int len = 1; len <= G; len++)
	{
		for (int start = 0; start <= G - len; start++)
		{
			if (!hasFound)
				dfs(start, len - 1);
			else
				break;
		}
	}

	return 0;
}

void dfs(int start, int remainLen)
{
	visited[start] = true;
	if (remainLen == 0 )
		hasFound = check();
	else
	{
		for (int i = start + 1; i <= G - remainLen; i++)
		{
			if (!hasFound)
				dfs(i, remainLen - 1);
			else
				break;
		}
	}
	visited[start] = false;
}

bool check()
{
	int cnt = 0;
	bool isQualify = true;
	memcpy(s, min_req, V * sizeof(int));

	for (int i = 0; i < G; i++)
	{
		if (visited[i])
		{
			cnt++;
			for (int j = 0; j < V; j++)
				s[j] -= candidate[i][j];
		}
	}

	for (int i = 0; i < V; i++)
	{
		if (s[i] > 0)
		{
			isQualify = false;
			break;
		}
	}

	if (isQualify)
	{
		cout << cnt;
		for (int i = 0; i < G; i++)
			if (visited[i])
				cout << ' ' << i + 1;
		cout << endl;
	}

	return isQualify;
}