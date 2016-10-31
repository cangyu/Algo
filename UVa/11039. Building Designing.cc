#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 500000 + 5;

int a[N];

template<typename T>
struct mycmp 
{
	bool operator()(const T &lhs, const T &rhs) const
	{
		return abs(lhs) < abs(rhs);
	}
};

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	const int bits = 8 * sizeof(int) - 1;
	
	int T;
	cin >> T;
	for (int kase = 0; kase < T; ++kase)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n, mycmp<int>());
		
		int cnt = 1;
		for (int i = 1; i < n; i++)
		{
			if ((a[i] ^ a[i - 1])&(1 << bits))
				++cnt;
		}

		cout << cnt << endl;
	}

	return 0;
}