#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000 + 5;

int n, r[N], pleft[N], pright[N];

bool check(int t);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	while (cin >> n && n != 0)
	{
		for (int i = 1; i <= n; i++)
			cin >> r[i];
		
		if (n == 1)
		{
			cout << r[1] << endl;
			continue;
		}

		r[n + 1] = r[1];
		int p_min = 0, p_max = 0;
		for (int i = 1; i <= n; i++)
		{
			int t = r[i] + r[i + 1];
			if (t > p_min)
				p_min = t;
		}

		if (n % 2 != 0)
		{
			for (int i = 0; i <= n; i++)
			{
				int t = 3 * r[i];
				if (t > p_max)
					p_max = t;
			}

			while (p_min < p_max)
			{
				int p = p_min + (p_max - p_min) / 2;
				if (check(p))
					p_max = p;
				else
					p_min = p + 1;
			}
		}

		cout << p_min << endl;
	}

	return 0;
}

bool check(int t)
{
	//Init
	const int left_space = r[1], right_space = t - r[1];
	pleft[1] = r[1];
	pright[1] = 0;

	//Explore
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			int left_remain = left_space - pleft[i - 1];
			pleft[i] = min(left_remain, r[i]);
			pright[i] = r[i] - pleft[i];
		}
		else
		{
			int right_remain = right_space - pright[i - 1];
			pright[i] = min(right_remain, r[i]);
			pleft[i] = r[i] - pright[i];
		}
	}

	//Check
	return pleft[n] == 0;
}
