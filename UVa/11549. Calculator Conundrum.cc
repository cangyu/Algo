#include <iostream>

using namespace std;

int n, k;
int buf[50];

int next(int t);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		if (k < 2)//k=0��1�Ͳ�������
		{
			cout << k << endl;
			continue;
		}

		int ans = k;
		int t1 = k, t2 = k;
		do {
			t1 = next(t1);
			if (t1 > ans)
				ans = t1;

			t2 = next(t2);
			if (t2 > ans)
				ans = t2;
			t2 = next(t2);
			if (t2 > ans)
				ans = t2;
		} while (t1 != t2);
		cout << ans << endl;
	}
	return 0;
}

int next(int t)
{
	long long ts = (long long)t*t;//Ҫ������
	int cnt = 0;
	while (ts != 0)
	{
		buf[cnt++] = ts % 10;
		ts /= 10;
	}

	if (n >= cnt)
		return t*t;

	int ret = 0;
	for (int i = 0; i < n; i++)
		ret = ret * 10 + buf[--cnt];
	
	return ret;
}
