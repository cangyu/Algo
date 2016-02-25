/*
ID: yhcy1993
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLeapYear(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
			return (y % 400 == 0);
		else
			return true;
	}
	else
		return false;
}

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int n;
	fin >> n;

	int cnt[7] = { 0 };
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int pre = 3;

	for (int y = 1900; y < 1900+n; y++)
	{
		if (isLeapYear(y))
			days[2] = 29;
		else
			days[2] = 28;
		for (int m = 1; m <= 12; m++)
		{
			int pre_m = m - 1;
			if (pre_m == 0)
				pre_m = 12;

			int cur = (pre + days[pre_m]) % 7;
			++cnt[cur];
			pre = cur;
		}
	}

	fout << cnt[6] << ' ' << cnt[0] << ' ';
	for (int i = 1; i <= 4; i++)
		fout << cnt[i] << ' ';
	fout << cnt[5] << endl;

	fin.close();
	fout.close();

	return 0;
}