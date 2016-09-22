#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

struct Ant
{
	int index, pos, dir;

	bool operator<(const Ant &rhs) const
	{
		return pos < rhs.pos;
	}
};

/**
 * 关键在于发现两点：
 *     相遇=对穿而过；
 *     所有蚂蚁的相对位置不变！
 */
 int main(int argc, char **argv)
{
	int N = 0;
	cin >> N;
	for (int k = 0; k < N; ++k)
	{
		int L = 0, T = 0, n = 0;
		cin >> L >> T >> n;

		vector<Ant> ant(n);

		/* Input */
		for (int i = 0; i < n; i++)
		{
			char D;
			ant[i].index = i;
			cin >> ant[i].pos >> D;
			ant[i].dir = (D == 'L') ? -1 : 1;
		}

		/* 确定映射关系 */
		vector<int> place(n, -1);
		sort(ant.begin(), ant.end());
		for (int i = 0; i < n; i++)
			place[ant[i].index] = i;

		/* Move */
		for (int i = 0; i < n; i++)
			ant[i].pos += T*ant[i].dir;

		/* 重新标记 */
		sort(ant.begin(), ant.end());
		for (int i = 0; i < n - 1; i++)//注意下标范围
			if (ant[i].pos == ant[i + 1].pos)//根据相邻看是否相遇
				ant[i].dir = ant[i + 1].dir = 0;

		/* Output */
		printf("Case #%d:\n", k+1);
		for (int i = 0; i < n; i++)
		{
			if (ant[i].pos > L)
				printf("Fell off\n");
			else if (ant[i].dir == 0)
				printf("%d Turning\n", ant[i].pos);
			else
			{
				printf("%d ", ant[i].pos);
				if (ant[i].dir == 'L')
					printf("L\n");
				else
					printf("R\n");
			}
		}
	}
	return 0;
}
