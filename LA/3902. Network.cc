#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1000 + 5;

int n, s, k;
vector<int> gr[N], dep[N];
int parent[N];
bool visited[N];

void dfs1(int s, int d, int p);
int solve(void);
void dfs2(int s, int d, int p);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T = 0;
	cin >> T;

	while (T--)
	{
		//Init
		for (int i = 0; i < N; i++)
		{
			gr[i].clear();
			dep[i].clear();
		}
		memset(visited, 0, sizeof(visited));

		//Input
		cin >> n >> s >> k;
		int a = 0, b = 0;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a >> b;
			gr[a].push_back(b);
			gr[b].push_back(a);
		}

		//Build the tree
		dfs1(s, 0, -1);

		//Solve
		cout << solve() << endl;
	}

	return 0;
}

void dfs1(int s, int d, int p)
{
	parent[s] = p;

	if (gr[s].size() == 1 && d > k)//只考察深度大于k的叶子节点！
		dep[d].push_back(s);

	for (int i = 0; i < gr[s].size(); i++)
	{
		int x = gr[s][i];
		if (x != p)//单向
			dfs1(x, d + 1, s);
	}
}

int solve(void)
{
	int ans = 0;
	for (int d = n - 1; d > k; --d)
		for (int i = 0; i < dep[d].size(); i++)
		{
			int x = dep[d][i];
			if (visited[x])
				continue;

			int y = x;
			for (int j = 0; j < k; ++j)
				y = parent[y];

			dfs2(y, k, -1);
			++ans;
		}

	return ans;
}

void dfs2(int s, int d, int p)
{
	visited[s] = true;

	if (d > 0)
		for (int i = 0; i < gr[s].size(); i++)
		{
			int x = gr[s][i];
			if (x != p)
				dfs2(x, d - 1, s);
		}
}
