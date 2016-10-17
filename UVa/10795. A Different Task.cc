#include <iostream>

using namespace std;

const int N = 60 + 5;
int start[N], finish[N];

long long f(int pos[], int last, int target);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n = 0, case_cnt = 0;
	while (cin >> n && n != 0)
	{
		for (int i = 1; i <= n; i++)
			cin >> start[i];
		for (int i = 1; i <= n; i++)
			cin >> finish[i];

		int k = n;
		while (k >= 1 && start[k] == finish[k])
			--k;

		long long ans = 0;
		if (k >= 1)
		{
			int other = 6 - start[k] - finish[k];
			ans = f(start, k - 1, other) + 1 + f(finish, k - 1, other);//移动的对称性
		}

		cout << "Case " << ++case_cnt << ": " << ans << endl;
	}

	return 0;
}

long long f(int pos[], int last, int target)
{
	if (last == 0)
		return 0;
	else if (pos[last] == target)
		return f(pos, last - 1, target);
	else
		return f(pos, last - 1, 6 - target - pos[last]) + ((long long)1 << last - 1);//加减在移位之前
}
