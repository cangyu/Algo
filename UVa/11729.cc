#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1000 + 5;

struct Job
{
	int B;
	int J;

	bool operator<(const Job &rhs) const
	{
		return J > rhs.J;//ִ��ʱ�䳤�������ǰ��
	}
};

int main(int argc, char **argv)
{
	int n = 0, cnt = 1;
	while (scanf("%d", &n) == 1 && n)
	{
		vector<Job> v(n);

		for (int i = 0; i < n; i++)
			scanf("%d%d", &v[i].B, &v[i].J);

		sort(v.begin(), v.end());

		int tB = 0, tJ = 0;
		int total = 0;

		for (int i = 0; i < n; i++)
		{
			tB += v[i].B;
			tJ = tB + v[i].J;
			total = max(total, tJ);//�������ͬʱ���У�������Ŀ
		}

		printf("Case %d: %d\n", cnt, total);
		++cnt;
	}
	
	return 0;
}
