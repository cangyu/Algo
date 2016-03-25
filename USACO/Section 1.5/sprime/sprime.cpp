/*
ID: yhcy1991
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int candidate0[4] = { 2, 3, 5, 7 };
int candidate1[4] = { 1, 3, 7, 9 };

bool isPrime(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x%i == 0)
			return false;
	return true;
}
void dfs(int curNum, int curPos, const int len, ofstream &out)
{
	if (curPos == len)
	{
		if (isPrime(curNum))
			out << curNum << endl;
		return;
	}

	if (curPos == 0)
	{
		for (int i = 0; i < 4; i++)
			dfs(candidate0[i], 1, len, out);
	}
	else
	{
		curNum *= 10;
		for (int i = 0; i < 4; i++)
			if (isPrime(curNum + candidate1[i]))
				dfs(curNum + candidate1[i], curPos + 1, len, out);
	}
}

int main()
{
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");

	int n;
	fin >> n;

	dfs(0, 0, n, fout);
	
	fin.close();
	fout.close();
	return 0;
}