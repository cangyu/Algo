#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 20005;
int dragon[maxn], knight[maxn];

int main()
{
	int n, m;

	while (scanf("%d%d", &n, &m) == 2 && n && m)
	{
		for (int i = 0; i < n; i++)
			cin >> dragon[i];
		for (int i = 0; i < m; i++)
			cin >> knight[i];

		if (n > m)
		{
			cout << "Loowater is doomed!" << endl;
			continue;
		}

		sort(dragon, dragon + n);
		sort(knight, knight + m);

		int curHead = 0;
		int cost = 0;

		for (int i = 0; i < m; i++)
		{
			if (knight[i] >= dragon[curHead])//从小到大排列，每次取到刚好capable的knight
			{
				cost += knight[i];
				++curHead;
				if (curHead >= n)
					break;
			}
		}

		if (curHead < n)
			cout << "Loowater is doomed!" << endl;
		else
			cout << cost << endl;
	}

	return 0;
}
