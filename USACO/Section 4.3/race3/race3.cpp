/*
ID: yhcy1991
PROG: race3
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxVertexCnt = 52;

int startIndex = 0, endIndex = 0;
int vertexCnt = 0;
int adjList[maxVertexCnt][maxVertexCnt] = { 0 };

bool visited1[maxVertexCnt], visited2[maxVertexCnt];
int ans1[maxVertexCnt] = { 0 }, ans2[maxVertexCnt] = { 0 };

void dfs(int start, bool visited[]);

int main(int argc, char** argv)
{
	freopen("race3.in", "r", stdin);
	freopen("race3.out", "w", stdout);

	int end = 0;
	cin >> end;
	while (end !=-1)
	{
		int &cnt = adjList[vertexCnt][0];
		while (end != -2)
		{
			adjList[vertexCnt][++cnt] = end;
			cin >> end;
		}
		++vertexCnt;
		cin >> end;
	}
	endIndex = vertexCnt - 1;

	for (int imp = 1; imp < endIndex; imp++)//the intermediate point
	{
		memset(visited1, 0, sizeof(visited1));
		visited1[imp] = true;
		dfs(0, visited1);
		if (!visited1[endIndex])
			ans1[++ans1[0]] = imp;
	}

	cout << ans1[0];
	for (int i = 1; i <= ans1[0]; i++)
		cout << ' ' << ans1[i];
	cout << endl;

	for (int i = 1; i <= ans1[0]; i++)//注意：i只是序号，不是真正的节点标号！！！
	{
		memset(visited1, 0, sizeof(visited1));
		memset(visited2, 0, sizeof(visited2));

		dfs(ans1[i], visited1);

		visited2[ans1[i]] = true;
		dfs(0, visited2);

		bool ok = true;
		for (int j = 0; j < vertexCnt; j++)
		{
			if (j != ans1[i] && visited1[j] && visited2[j])
			{
				ok = false;
				break;
			}
		}

		if (ok)
			ans2[++ans2[0]] = ans1[i];
	}

	cout << ans2[0];
	for (int i = 1; i <= ans2[0]; i++)
		cout << ' ' << ans2[i];
	cout << endl;

	return 0;
}

void dfs(int start, bool visited[])
{
	if (visited[start])
		return;

	visited[start] = true;
	for (int i = 1; i <= adjList[start][0]; i++)
	{
		int end = adjList[start][i];
		if (!visited[end])
			dfs(end, visited);
	}
}
