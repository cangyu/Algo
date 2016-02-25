/*
ID: yhcy1991
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void convert(int n, int base, string &res);
bool isPal(const string &s);

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int base;
	fin >> base;
	for (int i = 1; i <= 300; i++)
	{
		int n = i*i;
		string converted;
		convert(n, base, converted);
		if (isPal(converted))
		{
			string ori;
			convert(i, base, ori);
			fout << ori << ' ' << converted << endl;
		}

	}
	
	fin.close();
	fout.close();
	return 0;
}

void convert(int n, int base, string &res)
{
	while (n)
	{
		int curDigit = n%base;
		if (curDigit < 10)
			res.append(1, '0' + curDigit);
		else
			res.append(1, 'A' + curDigit - 10);
		n -= curDigit;
		n /= base;
	}
	reverse(res.begin(), res.end());
}

bool isPal(const string &s)
{
	int i = 0, j = s.length() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		++i, --j;
	}
	return true;
}