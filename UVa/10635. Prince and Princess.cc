#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

const int N = 250 * 250 + 5;

int n, p, q;
int num[N], S[N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int case_cnt=1;case_cnt<=T; ++case_cnt)
	{
		//在输入过程中构造map
		cin >> n >> p >> q;
		memset(num, 0, sizeof(num));
		int x;
		for (int i = 1; i <= p + 1; i++)
		{
			cin >> x;
			num[x] = i;
		}

		int cnt = 0;
		for (int i = 0; i < q + 1; i++)
		{
			cin >> x;
			if (num[x])
				S[cnt++] = num[x];
		}

		//求S中的LIS
		for_each(num, num + cnt, [](int &a) {a = numeric_limits<int>::max(); });
		int ans = 0;
		for (int i = 0; i < cnt; i++)
		{
			int k = lower_bound(num, num + cnt, S[i]) - num;
			num[k] = S[i];
			ans = max(ans, k + 1);
		}
		cout << "Case " << case_cnt << ": " << ans << endl;
	}

	return 0;
}
