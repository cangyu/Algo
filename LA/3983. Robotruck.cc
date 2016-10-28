#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100000 + 5;

int d[N], total_dist[N], dist2origin[N], weight[N], q[N];

int w(int i, int j);
int g(int i);
int f(int i);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int C, n;
		cin >> C >> n;
		int xp = 0, yp = 0;
		d[0] = total_dist[0] = dist2origin[0] = weight[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y >> weight[i];
			weight[i] += weight[i - 1];
			dist2origin[i] = abs(x) + abs(y);
			total_dist[i] = total_dist[i - 1] + abs(x - xp) + abs(y - yp);
			xp = x;
			yp = y;
		}

		q[0] = q[1] = 0;//��Ȼ��������ȫ�ֱ����ĳ�ֵΪ0�� ��Ϊ���������Ա߽������Ĵ�����û���дһ��
		int front = 1, rear = 1;
		for (int i = 1; i <= n; i++)//��������ά����С
		{
			while (front <= rear && w(q[front] + 1, i) > C)
				++front;
			d[i] = f(q[front]) + g(i);//���ǰi������С��C�����ʼfront����1��q[front]��ӳ�䵽0����f��f(0)��Ϊ0����g(i)�պ���һ���������е�·�����ۣ����Բ���ì��
			while (front <= rear && f(i) <= f(q[rear]))
				--rear;
			q[++rear] = i;
		}

		cout << d[n] << endl;
		if (T)
			cout << endl;
	}

	return 0;
}

inline int w(int i, int j)//[,]
{
	return weight[j] - weight[i - 1];
}

inline int g(int i)
{
	return total_dist[i] + dist2origin[i];
}

inline int f(int i)
{
	return d[i] + dist2origin[i + 1] - total_dist[i + 1];//dp���ѹ���j�Ĳ�����ȡ����
}