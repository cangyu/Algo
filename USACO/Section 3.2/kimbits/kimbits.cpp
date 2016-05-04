/*
ID: yhcy1991
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned int u32;

u32 N, L, I, f[32][32] = { 0 };

u32 calc(int n, int l);

int main(int argc, char **argv)
{
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);

	cin >> N >> L >> I;
	memset(f, 0, sizeof(f));

	for (int i = N; i >= 1; i--)
	{
		calc(i - 1, L);
		if (f[i - 1][L] < I)//nλ������n-1λ������ǰ�油0��1�õ��ģ�f[i][j]��ָ���г���Ϊi��01���У�1�ĸ���������j��01�������������Ʒ���������Ϻ��ʽ������Ҫע��߽�
		{
			cout << 1;
			I -= f[i - 1][L];
			L--;
		}
		else
			cout << 0;
	}

	cout << endl;
	return 0;
}

u32 calc(int n, int l)
{
	if (n == 0 || l == 0)
		return f[n][l] = 1;//ע�����ñ߽�
	else if (f[n][l] != 0)
		return f[n][l];
	else
		return	f[n][l] = calc(n - 1, l) + calc(n - 1, l - 1);//���Ʒ���
}