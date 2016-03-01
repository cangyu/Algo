/*
ID: yhcy1991
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_SIZE = 250 * 250 * 2 + 1;

int bisquare[MAX_SIZE] = { 0 };
int hasExist[MAX_SIZE] = { 0 };
int flag[MAX_SIZE] = { 0 };
int roundInfo[MAX_SIZE] = { 0 };

typedef struct prog {
	int start;
	int difference;
	prog(int a, int b) :start(a), difference(b) {}
}ProgTypeDef,*pProgTypeDef;

bool MyProgressionCmp(const ProgTypeDef &p1, const ProgTypeDef &p2)
{
	/*
	if (p1.difference < p2.difference)
		return true;
	else if (p1.difference == p2.difference)
		return p1.start < p2.start;
	else
		return false;
	*/
	return p1.start < p2.start;
}

int main()
{
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	int n, m;
	fin >> n >> m;
	fin.close();

	int k = 0;
	for (int p = 0; p <= m; p++)
	{
		for (int q = 0; q <= m; q++)
		{
			int temp = p*p + q*q;
			if (hasExist[temp] == 0)
			{
				hasExist[temp] = 1;
				bisquare[k++] = temp;
			}
		}
	}
	sort(bisquare, bisquare + k);

	int validCnt = 0;
	
	for (int gap = 1; gap <= 2 * m*m / (n - 1); gap++)
	{
		vector<ProgTypeDef> prog;
		int round = 0;
		memset(roundInfo, 0, sizeof(int)*MAX_SIZE);
		memset(flag, 0, sizeof(int)*MAX_SIZE);

		//mark up
		for (int i = 0; i < k; i++)
		{
			if (flag[i] != 0)
				continue;

			round++;
			int j = 0, cnt = 0;

			if (bisquare[i] + (n - 1)*gap>bisquare[k - 1] || i + n - 1 >= k)
			{
				roundInfo[round] = cnt;
				break;
			}

			while (i + j < k)
			{
				if (flag[i + j] != 0)
				{
					j++;
					continue;
				}

				if (bisquare[i + j] - bisquare[i]>cnt*gap)
					break;
				else if (bisquare[i + j] - bisquare[i] == cnt*gap)
				{
					flag[i + j] = round;
					cnt++;
				}
				j++;
			}
			roundInfo[round] = cnt;
		}

		//organize
		for (int i = 1; i <= round; i++)
		{
			if (roundInfo[i] >= n)
			{
				int ansCnt = roundInfo[i] - n + 1;
				int curCnt = 0;
				for (int j = 0; j < k; j++)
				{
					if (flag[j] == i)
					{
						ProgTypeDef p(bisquare[j], gap);
						prog.push_back(p);
						validCnt++;
						curCnt++;
						if (curCnt >= ansCnt)
							break;
					}
				}
			}
		}

		sort(prog.begin(), prog.end(),MyProgressionCmp);

		for (int i = 0; i < prog.size(); i++)
			fout << prog[i].start << ' ' << prog[i].difference << endl;
	}

	if (validCnt == 0)
		fout << "NONE" << endl;

	fout.close();
	return 0;
}
