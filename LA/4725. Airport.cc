#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5000 + 5, MAX_NUM = 20;
int n, a[N], b[N];

bool check(int M);

//按需累加，以加待减
//可能有极端case导致L为0，L最好取有物理意义的1
int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;

		int L = 0, R = MAX_NUM * n;
		for (int i = 1; i <= n; i++)
			cin >> a[i] >> b[i];	

		while (L < R)
		{
			int M = (L + R) / 2;
			if (check(M))
				R = M;
			else
				L = M + 1;
		}

		cout << max(L - 1, 0) << endl;
	}

	return 0;
}

bool check(int M)
{
	int A = 0, B = 0, av_a = 0, av_b = 0, av_t = 0;
	for (int i = 1; i <= n; i++)
	{
		A += a[i];
		B += b[i];

		if (A > M)
		{
			int deduct = min(A - M, min(av_a, av_t));
			A -= deduct;
			av_a -= deduct;
			av_t -= deduct;
		}
		if (B > M)
		{
			int deduct = min(B - M, min(av_b, av_t));
			B -= deduct;
			av_b -= deduct;
			av_t -= deduct;
		}

		if (A > M || B > M)
			return false;

		if (av_a < A)
			++av_a;
		if (av_b < B)
			++av_b;
		if (av_t < A + B)
			++av_t;
	}

	return true;
}
