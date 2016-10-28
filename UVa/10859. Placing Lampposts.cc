#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000 + 5;
const int M = 2000;

vector<int> adj[N];
int d[N][2];
bool visited[N][2];

int dp(int i, int j, int p);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
			adj[i].clear();

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		//dfs, 将两个优化目标转化成一个x=M*a+c
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (!visited[i][0])
				ans += dp(i, 0, -1);

		cout << ans / M << ' ' << m - ans%M << ' ' << ans%M << endl;
	}

	return 0;
}

int dp(int i, int j, int p)
{
	if (visited[i][j])
		return d[i][j];

	visited[i][j] = true;

	//决策1：在i处放lamp
	int ans1 = M;//表示了x中a随深度的增加而增加
	for (int k = 0; k < adj[i].size(); k++)
		if (adj[i][k] != p)
			ans1 += dp(adj[i][k], 1, i);//构成x中的Ma, 输入已经保证是有向无环了，所以不必担心

	if (j == 0 && p >= 0)//corner, 在根部j=0, 不用加，注意别把==写成了=。。。
		++ans1;//构成x中的c

	//决策2：在i处不放lamp
	if (j == 1 || p < 0)
	{
		int ans2 = 0;
		for (int k = 0; k < adj[i].size(); k++)
			if (adj[i][k] != p)
				ans2 += dp(adj[i][k], 0, i);//构成x中的Ma

		if (p >= 0)
			++ans2;

		ans1 = min(ans1, ans2);
	}

	return d[i][j] = ans1;
}
