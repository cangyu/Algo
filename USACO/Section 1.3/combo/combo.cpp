/*
ID: yhcy1991
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int calcOverlap(int a, int b, int n);

int main()
{
	ifstream fin("combo.in");
	ofstream fout("combo.out");

	int n;
	fin >> n;
	int john[3], master[3];
	for (int i = 0; i < 3; i++)
		fin >> john[i];
	for (int i = 0; i < 3; i++)
		fin >> master[i];

	int cnt = pow(min(n, 5), 3);

	if (n <= 5)
	{
		fout << cnt << endl;
		fin.close();
		fout.close();
		return 0;
	}
	else
		cnt *= 2;

	int overlap[3] = { 0 };
	int cnt_overlap = 1;

	for (int i = 0; i < 3; i++)
	{
		overlap[i] = calcOverlap(john[i], master[i], n);
		cnt_overlap *= overlap[i];
	}
	cnt -= cnt_overlap;
	fout << cnt << endl;
	fin.close();
	fout.close();
	return 0;
}

int calcOverlap(int a, int b, int n)
{
	if (a > b)
		swap(a, b);
	int k = min(b - a, a + n - b);
	int part1 = max(0, 5 - k);
	int part2 = n >= k + 5 ? 0 : (k + 5) - n;
	return part1 + part2;
}
