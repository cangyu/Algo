/*
ID: yhcy1991
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool visited[21][21][21] = { false };
bool recorded[21] = { false };
int A, B, C;

void dfs(int a, int b, int c)
{
	if (visited[a][b][c])
		return;
	else
		visited[a][b][c] = true;

	if (a == 0 && !recorded[c])
		recorded[c] = true;

	int m = 0;
	//6 kinds of possible branches
	m = min(c, A - a);
	dfs(a + m, b, c - m);

	m = min(c, B - b);
	dfs(a, b + m, c - m);

	m = min(b, A - a);
	dfs(a + m, b - m, c);

	m = min(b, C - c);
	dfs(a, b - m, c + m);

	m = min(a, B - b);
	dfs(a - m, b + m, c);

	m = min(a, C - c);
	dfs(a - m, b, c + m);
}

int main()
{
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> A >> B >> C;
	dfs(0, 0, C);

	int cnt = 0;
	for (int i = 0; i <= C; i++)
	{
		if (recorded[i])
		{
			cnt++;
			if (cnt == 1)
				fout << i;
			else
				fout << ' ' << i;
		}
	}
	fout << endl;

	fin.close();
	fout.close();
	return 0;
}