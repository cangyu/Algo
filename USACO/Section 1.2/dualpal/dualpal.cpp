/*
ID: yhcy1991
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int n);
bool isPal(int n, int base);

int main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int n, s;
	fin >> n >> s;

	int start = s + 1;
	while (n)
	{
		if (check(start))
		{
			fout << start << endl;
			--n;
		}
		++start;
	}

	fin.close();
	fout.close();
	return 0;
}

bool check(int n)
{
	int cnt = 0;
	for (int base = 2; base <= 10; base++)
	{
		if (cnt < 2)
		{
			if (isPal(n, base))
				++cnt;
		}
		else
			break;
	}
	if (cnt >= 2)
		return true;
	else
		return false;
}

bool isPal(int n, int base)
{
	string res;
	while (n)
	{
		int k = n%base;
		res.append(1, k + '0');
		n -= k;
		n /= base;
	}
	int i = 0, j = res.length() - 1;
	while (i < j)
	{
		if (res[i] != res[j])
			return false;
		++i, --j;
	}
	return true;
}