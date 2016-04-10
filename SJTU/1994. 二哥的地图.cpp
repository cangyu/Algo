//用dfs来标记已访问过的坐标，只起标记作用，计数部分由调用程序处理

#include<iostream>
#include<vector>

using namespace std;

int process(vector<vector<int> > &map, int n, int m);
void dfs(vector<vector<int> > &map, int i, int j, int n, int m);

int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int> > map(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	int country_cnt = process(map, n, m);

	cout << country_cnt << endl;
	//system("pause");
	return 0;
}

int process(vector<vector<int> > &map, int n, int m)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				ans++;
				dfs(map, i, j, n, m);
			}
		}
	}
	return ans;
}

void dfs(vector<vector<int> > &map, int i, int j, int n, int m)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return;
	if (map[i][j] != 0)
		return;
	else
	{
		map[i][j] = 1;
		dfs(map, i, j + 1, n, m);
		dfs(map, i, j - 1, n, m);
		dfs(map, i + 1, j, n, m);
		dfs(map, i - 1, j, n, m);
	}
}
