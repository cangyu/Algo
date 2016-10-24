#include <iostream>
#include <map>
#include <cstring>

using namespace std;

const int N = 24;

int n;
int A[N];
map<int, int> mt;

int count_bit(int x);

int main(int argc, char **argv)//分两半，以第一部分为样本基础，再在此基础上寻找XOR相同的另一半
{
	ios::sync_with_stdio(false);

	while (cin >> n)
	{
		char seq[1000];
		memset(A, 0, sizeof(A));
		for (int i = 0; i < n; i++)
		{
			cin >> seq;
			for (int j = 0; seq[j] != '\0'; ++j)
				A[i] ^= (1 << (seq[j] - 'A'));
		}

		mt.clear();
		int n1 = n / 2, sample_cnt = 1 << n1;
		for (int com = 0; com < sample_cnt; ++com)
		{
			int x = 0;
			for (int j = 0; j < n1; ++j)
				if (com & (1 << j))
					x ^= A[j];

			if (!mt.count(x) || count_bit(mt[x]) < count_bit(com))
				mt[x] = com;
		}

		int ans = 0;

		int n2 = n - n1, test_cnt = 1 << n2;
		for (int com = 0; com < test_cnt; ++com)
		{
			int x = 0;
			for (int j = 0; j < n2; ++j)
				if (com & (1 << j))
					x ^= A[n1 + j];

			if (mt.count(x) && count_bit(ans) < count_bit(mt[x]) + count_bit(com))
				ans = (com << n1) ^ mt[x];
		}

		cout << count_bit(ans) << endl;
		for (int i = 0; i < n; i++)
			if (ans & (1 << i))
				cout << i + 1 << ' ';
		cout << endl;
	}

	return 0;
}

int count_bit(int x)
{
	return x == 0 ? 0 : count_bit(x / 2) + (x & 1);
}
