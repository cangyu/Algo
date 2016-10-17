#include <iostream>

using namespace std;

const int di[] = { 0,-1,0,1 };
const int dj[] = { -1,0,1,0 };

bool check(int ci, int cj, int ch);
bool bound_check(const int &i, const int &j);

const int N = 16;
int n = 0;
char grid[N][N];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T = 0;
	cin >> T;
	for (int case_cnt = 1; case_cnt <= T; ++case_cnt)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> grid[i];//ÕûĞĞ¶ÁÈë

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if(grid[i][j]=='.')
					for(char c='A';c<='Z';++c)
						if (check(i, j, c))
						{
							grid[i][j] = c;
							break;
						}

		cout << "Case " << case_cnt << ":" << endl;
		for (int i = 0; i < n; i++)
			cout << grid[i] << endl;
	}
	return 0;
}

bool check(int ci, int cj, int ch)
{
	for (int k = 0; k < 4; k++)
	{
		int ti = ci + di[k];
		int tj = cj + dj[k];

		if (bound_check(ti, tj))
		{
			if (grid[ti][tj] == ch)
				return false;
		}
	}

	return true;
}

inline bool bound_check(const int &i, const int &j)
{
	return i >= 0 && i < n && j >= 0 && j < n;
}
