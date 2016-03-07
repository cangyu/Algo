//����������˵�ʱ���п�����������Runtime Error��Ҫ�ȴ��������˷�
//��������ͨ�Ļ�������3Ԫ���Sparse Matrix�����������ǲ��һ��ǽ�������O(n)����ȻTLE
//��������������¼���н�������±�ӳ���ϵ����ͨ��hash�����ҵ����ݣ��˴���������̽���������ͻ
//һ����˵��hash��ֵȡ1.1n-1.7n����������

#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

using namespace std;

const int MAX_NUM = 100000;
const int HASH_MAX = 14587;

struct Position2D {
	int x;
	int y;
	Position2D() :x(-1), y(-1) {}
};

Position2D spmat[HASH_MAX];
int content[HASH_MAX] = { 0 };

int main()
{
	int xx[MAX_NUM] = { 0 }, yy[MAX_NUM] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < MAX_NUM; i++)
		xx[i] = yy[i] = i;

	for (int i = 0; i < n; i++)
	{
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		int pos = (x % HASH_MAX)*(y%HASH_MAX) % HASH_MAX;//important
		while (spmat[pos].x != -1)
			pos = (pos + 1) % HASH_MAX;
		spmat[pos].x = x;
		spmat[pos].y = y;
		content[pos] = t;
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		int pos, tmp;
		scanf("%d%d%d", &op, &a, &b);
		switch (op)
		{
		case 0:
			tmp = xx[a], xx[a] = xx[b], xx[b] = tmp;
			break;
		case 1:
			tmp = yy[a], yy[a] = yy[b], yy[b] = tmp;
			break;
		case 2:
			a = xx[a], b = yy[b];
			pos = (a % HASH_MAX)*(b % HASH_MAX) % HASH_MAX;
			while (spmat[pos].x != -1 && (spmat[pos].x != a || spmat[pos].y != b))
				pos = (pos + 1) % HASH_MAX;
			printf("%d\n", content[pos]);
			break;
		default:
			break;
		}
	}

	return 0;
}