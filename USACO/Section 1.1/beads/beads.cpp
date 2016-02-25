/*
ID: yhcy1991
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int n;
	fin >> n;
	string s;
	fin >> s;

	int maxbeads = 0;

	bool hasMeetB = false;
	bool hasMeetR = false;
	for (int i = 0; i < n; i++)
	{
		if (!hasMeetB || !hasMeetR)
		{
			if (s[i] == 'b')
				hasMeetB = true;
			else if (s[i] == 'r')
				hasMeetR = true;
			else
				continue;
		}
		else
			break;
	}

	if (!hasMeetB || !hasMeetR)
	{
		fout << n << endl;
		fin.close();
		fout.close();
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] != s[(i - 1 + n) % n])
		{
			int left_cnt = 0;
			int pre = (i - 1 + n) % n;
			if (s[pre] == 'w')
			{
				while (s[pre] == 'w')
				{
					++left_cnt;
					pre = (pre - 1 + n) % n;
				}
			}
			char left_elem = s[pre];
			while (s[pre] == 'w' || s[pre] == left_elem)
			{
				++left_cnt;
				pre = (pre - 1 + n) % n;
			}

			int rigth_cnt = 0;
			int next = i;
			if (s[next] == 'w')
			{
				while (s[next] == 'w')
				{
					++rigth_cnt;
					next = (next + 1) % n;
				}
			}
			char right_elem = s[next];
			while (s[next] == 'w' || s[next] == right_elem)
			{
				++rigth_cnt;
				next = (next + 1) % n;
			}

			int sum = left_cnt + rigth_cnt;
			sum = min(sum, n);
			maxbeads = max(maxbeads, sum);
		}
	}
	fout << maxbeads << endl;
	fin.close();
	fout.close();
	return 0;
}