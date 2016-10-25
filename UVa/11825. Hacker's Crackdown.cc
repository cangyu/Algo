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

		//�γ����п��ܵĸ��ǣ��Ӹ��ǵĽǶ��������̻�����
		for (int subset = 0; subset < (1 << n); ++subset)
		{
			cover[subset] = 0;
			for (int i = 0; i < n; i++)
				if (subset & (1 << i))
					cover[subset] |= p[i];
		}

		//����ÿ��subset��������Ԫ�ع��ɵ�subset(denoted as subset^2),����֤����Щsubset^2��������subset(������֮ǰ)
		//������Ҫ��С�����������subset�������Ϊf[(1<<n)-1]
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