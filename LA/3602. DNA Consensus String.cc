#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000 + 5;
const char dna[4] = { 'A', 'C', 'G', 'T' };

int cnt[N][4];
char s[N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int m, n;
		cin >> m >> n;

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < m; i++)
		{
			cin >> s;
			for (int j = 0; j < n; j++)
				switch (s[j])
				{
				case 'A':
					++cnt[j][0]; break;
				case 'C':
					++cnt[j][1]; break;
				case 'G':
					++cnt[j][2]; break;
				case 'T':
					++cnt[j][3]; break;
				default:
					break;
				}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
				cnt[i][j] = m - cnt[i][j];

		int hamming = 0;
		for (int i = 0; i < n; i++)
		{
			char c = 'A';
			int cur_cnt = cnt[i][0];
			for (int j = 1; j < 4; j++)
				if (cnt[i][j] < cur_cnt)
				{
					c = dna[j];
					cur_cnt = cnt[i][j];
				}

			s[i] = c;
			hamming += cur_cnt;
		}

		s[n] = 0;
		cout << s << endl;
		cout << hamming << endl;
	}

	return 0;
}
