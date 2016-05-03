/*
ID: yhcy1991
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int k, n;
int v[52] = { 0 };
int f[2000004] = { 0 };

int main(int argc, char **argv)//������˳�������ǣ������Ǵ�Ʊ��˳�򣬷�����кܶ���ν�ļ��㣬�������ñ�־λ��ʱ�������ϵ���������鷳
{
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);

	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v, v + n);
	const int max_postage = k*v[n - 1];
	for (int i = 0; i < n; i++)
		f[v[i]] = 1;

	int w = 1;
	while (w <= max_postage)
	{
		if (f[w] == 0 || f[w] > k)
			break;

		for (int i = 0; i < n; i++)
		{
			if (f[w + v[i]] == 0)
				f[w + v[i]] = f[w] + 1;
			else
				f[w + v[i]] = min(f[w + v[i]], f[w] + 1);
		}
		w++;
	}

	cout << w - 1 << endl;
	return 0;
}
