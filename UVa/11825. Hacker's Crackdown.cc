#include <iostream>
#include <algorithm>

using namespace std;

const int N = 16;

int p[N];
int cover[1 << N], f[1 << N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n = 0, case_cnt = 0;
	while (cin >> n && n)
	{
		//Input
		for (int i = 0; i < n; i++)
		{
			int m, x;
			cin >> m;
			p[i] = 1 << i;
			for (int j = 0; j < m; j++)
			{
				cin >> x;
				p[i] |= 1 << x;
			}
		}

		//形成所有可能的覆盖，从覆盖的角度入手来刻画分组
		for (int subset = 0; subset < (1 << n); ++subset)
		{
			cover[subset] = 0;
			for (int i = 0; i < n; i++)
				if (subset & (1 << i))
					cover[subset] |= p[i];
		}

		//由于每个subset依赖于其元素构成的subset(denoted as subset^2),可以证明这些subset^2都不大于subset(即在其之前)
		//所以需要从小到大，逐个计算subset，最后结果为f[(1<<n)-1]
		f[0] = 0;
		const int ALL = (1 << n) - 1;
		for (int s = 1; s <= ALL; ++s)
		{
			f[s] = 0;
			for (int s2 = s; s2; s2 = (s2 - 1)&s)
				if (cover[s2] == ALL)
					f[s] = max(f[s], f[s^s2] + 1);
		}

		//Output
		cout << "Case " << ++case_cnt << ": " << f[ALL] << endl;
	}

	return 0;
}