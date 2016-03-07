/*
ID: yhcy1991
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include<algorithm>

//Trade memory for speed
//查找的时候有hash的思维去找，而不是scan

using namespace std;

const int MAX_NUM = 2 * 250 * 250 + 1;

int bisquare[MAX_NUM] = { 0 };
int numMark[MAX_NUM] = { 0 };
int gap[MAX_NUM] = { 0 };
int gapMark[MAX_NUM] = { 0 };

int main()
{
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	int n, m;
	fin >> n >> m;
	fin.close();

	for (int p = 0; p <= m; p++)
		for (int q = p; q <= m; q++)
			numMark[p*p + q*q] = 1;

	int numCnt = 0;
	for (int i = 0; i < MAX_NUM; i++)
		if (numMark[i])
			bisquare[numCnt++] = i;

	for (int i = 1; i < numCnt; i++)
		for (int j = 0; j < i; j++)
			gapMark[bisquare[i] - bisquare[j]] = 1;

	//fout << numCnt << endl;

	int gapCnt = 0;
	for (int i = 0; i < MAX_NUM; i++)
		if (gapMark[i])
			gap[gapCnt++] = i;

	//fout << gapCnt << endl;

	int validCnt = 0;
	for (int i = 0; i < gapCnt; i++)
	{
		for (int j = 0; j < numCnt; j++)
		{
			if (bisquare[j] + (n - 1)*gap[i]>bisquare[numCnt - 1])
				break;
			else
			{
				int flag = 1;
				for (int k = 1; k < n; k++)
					if (numMark[bisquare[j] + k*gap[i]] == 0)//nice!
					{
						flag = 0;
						break;
					}
				if (flag)
				{
					fout << bisquare[j] << ' ' << gap[i] << endl;
					validCnt++;
				}

			}
		}
	}

	if (validCnt == 0)
		fout << "NONE" << endl;
	
	fout.close();
	return 0;
}
