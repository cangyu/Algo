#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n = 0;
	while (cin >> n)
	{
		vector<long long> C(n);

		long long sum = 0, cur = 0;
		C[0] = 0;
		cin >> sum;

		for (int i = 1; i < n; i++)
		{
			C[i] = sum;
			cin >> cur;
			sum += cur;
		}

		long long M = sum / n;
		for (int i = 1; i < n; i++)
			C[i] -= i*M;

		sort(C.begin(), C.end());//��������ȡ��λ�������
		long long x0 = C[n / 2];

		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += abs(x0 - C[i]);//ת������ѧ���⣬�����Ͼ���ֵ����С

		cout << ans << endl;
	}

	return 0;
}
