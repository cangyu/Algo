/*
ID: yhcy1991
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkNoTransform(const vector<string> &g1, const vector<string> &g2, int n);
bool check90(const vector<string> &g1, const vector<string> &g2, int n);
bool check180(const vector<string> &g1, const vector<string> &g2, int n);
bool check270(const vector<string> &g1, const vector<string> &g2, int n);
bool checkReflect(const vector<string> &g1, const vector<string> &g2, int n);
void reflect(vector<string> &g, int n);

int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	int n;
	fin >> n;
	vector<string> original(n), transformed(n);
	for (int i = 0; i < n; i++)
		fin >> original[i];
	for (int i = 0; i < n; i++)
		fin >> transformed[i];

	if (check90(original, transformed, n))
		fout << 1 << endl;
	else if (check180(original, transformed, n))
		fout << 2 << endl;
	else if (check270(original, transformed, n))
		fout << 3 << endl;
	else if (checkReflect(original, transformed, n))
		fout << 4 << endl;
	else 
	{
		reflect(original, n);
		if (check90(original, transformed, n) || check180(original, transformed, n) || check270(original, transformed, n))
			fout << 5 << endl;
		else
		{
			reflect(original, n);
			if (checkNoTransform(original, transformed, n))
				fout << 6 << endl;
			else
				fout << 7 << endl;
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}

bool checkNoTransform(const vector<string> &g1, const vector<string> &g2, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g1[i][j] != g2[i][j])
				return false;
		}
	}
	return true;
}

bool check90(const vector<string> &g1, const vector<string> &g2, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g1[i][j] != g2[j][n - 1 - i])
				return false;
		}
	}
	return true;
}

bool check180(const vector<string> &g1, const vector<string> &g2, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g1[i][j] != g2[n - 1 - i][n - 1 - j])
				return false;
		}
	}
	return true;
}

bool check270(const vector<string> &g1, const vector<string> &g2, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g1[i][j] != g2[n - 1 - j][i])
				return false;
		}
	}
	return true;
}

bool checkReflect(const vector<string> &g1, const vector<string> &g2, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g1[i][j] != g2[i][n - 1 - j])
				return false;
		}
	}
	return true;
}

void reflect(vector<string> &g, int n)
{
	for (int i = 0; i < n; i++)
		reverse(g[i].begin(), g[i].end());
}