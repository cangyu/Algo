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

		//dfs, �������Ż�Ŀ��ת����һ��x=M*a+c
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

	//����1����i����lamp
	int ans1 = M;//��ʾ��x��a����ȵ����Ӷ�����
	for (int k = 0; k < adj[i].size(); k++)
		if (adj[i][k] != p)
			ans1 += dp(adj[i][k], 1, i);//����x�е�Ma, �����Ѿ���֤�������޻��ˣ����Բ��ص���

	if (j == 0 && p >= 0)//corner, �ڸ���j=0, ���üӣ�ע����==д����=������
		++ans1;//����x�е�c

	//����2����i������lamp
	if (j == 1 || p < 0)
	{
		int ans2 = 0;
		for (int k = 0; k < adj[i].size(); k++)
			if (adj[i][k] != p)
				ans2 += dp(adj[i][k], 0, i);//����x�е�Ma

		if (p >= 0)
			++ans2;

		ans1 = min(ans1, ans2);
	}

	return d[i][j] = ans1;
}
