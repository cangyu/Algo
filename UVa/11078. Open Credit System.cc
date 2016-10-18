#include <iostream>

using namespace std;

int n = 0;
int cur, cur_max, max_diff;

 int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;

		max_diff = -150000;
		cin >> cur_max;
		for (int i = 1; i < n; i++)
		{
			cin >> cur;
			int cur_diff = cur_max - cur;
			if (cur_diff > max_diff)
				max_diff = cur_diff;
			if (cur > cur_max)
				cur_max = cur;
		}
		cout << max_diff << endl;
	}
	return 0;
}
