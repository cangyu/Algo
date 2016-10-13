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
 * �ؼ����ڷ������㣺
 *     ����=�Դ�������
 *     �������ϵ����λ�ò��䣡
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

		/* ȷ��ӳ���ϵ */
		vector<int> place(n, -1);
		sort(ant.begin(), ant.end());
		for (int i = 0; i < n; i++)
			place[ant[i].index] = i;

		/* Move */
		for (int i = 0; i < n; i++)
			ant[i].pos += T*ant[i].dir;

		/* ���±�� */
		sort(ant.begin(), ant.end());
		for (int i = 0; i < n - 1; i++)//ע���±귶Χ
			if (ant[i].pos == ant[i + 1].pos)//�������ڿ��Ƿ�����
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
