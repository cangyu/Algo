/*
ID: yhcy1991
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	int a[1005], b[1005];
	int c[4][4] = { 0 };
	int n;

	fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n);

	for (int i = 0; i < n; i++)
	{

	}

	fin.close();
	fout.close();
	return 0;
}
