/*
ID: yhcy1991
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class numTriangle
{
private:
	int r;
	int *data;
	int getIndex(int i, int j) const { return i*(i - 1) / 2 + j - 1; }

public:
	numTriangle(int R = 1) :r(R), data(new int[R*(R + 1) / 2]) {}
	~numTriangle()
	{
		delete[] data;
		r = 0;
	}
	int& operator() (int i, int j) //i,j are one based
	{
		return data[getIndex(i, j)];
	}

	int operator() (int i, int j) const
	{
		return data[getIndex(i, j)];
	}

	int getLineMax(int l)
	{
		if (l<1 || l>r)
			return -1;
		int startIndex = getIndex(l, 1);
		int endIndex = getIndex(l, l);
		int maxElem = data[startIndex];
		for (int i = startIndex + 1; i <= endIndex; i++)
		{
			if (data[i] > maxElem)
				maxElem = data[i];
		}
		return maxElem;
	}
};

int main()
{
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int R;
	fin >> R;
	numTriangle src(R);
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= i; j++)
			fin >> src(i, j);
	
	for (int i = 2; i <= R; i++)
	{
		src(i, 1) += src(i - 1, 1);
		src(i, i) += src(i - 1, i - 1);
	}

	for (int i = 3; i <= R; i++)
	{
		for (int j = 2; j <= i - 1; j++)
		{
			src(i, j) += max(src(i - 1, j - 1), src(i - 1, j));
		}
	}

	fout << src.getLineMax(R) << endl;

	fin.close();
	fout.close();
	return 0;
}