#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10000 + 5;
const int MAX_NUM = 1000000 + 5;
int a[N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	//freopen("ans.dat", "w", stdout);

	int n, case_cnt = 0;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		int max_cnt = 0, cur_num = -1, cur_cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == cur_num)
				++cur_cnt;
			else
			{
				max_cnt = max(max_cnt, cur_cnt);
				cur_num = a[i];
				cur_cnt = 1;
			}
		}
		max_cnt = max(max_cnt, cur_cnt);//corner case: n=1

		if (!max_cnt)
			exit(-1);

		vector<vector<int>> dist(max_cnt);
		int level = 0;

		for (int i = 0; i < n; i++)
		{
			dist[level].push_back(a[i]);
			level = (level + 1) % max_cnt;
		}

		if (case_cnt++)
			cout << endl;

		cout << dist.size() << endl;
		for (int i = 0; i < dist.size(); i++)
		{
			cout << dist[i][0];
			for (int j = 1; j < dist[i].size(); j++)
				cout << ' ' << dist[i][j];
			cout << endl;
		}
	}

	return 0;
}
