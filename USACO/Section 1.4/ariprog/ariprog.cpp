/*
ID: yhcy1991
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include<algorithm>

using namespace std;

int bisquare[250 * 250 + 1] = { 0 };
int hasExist[250 * 250 + 1] = { 0 };


int main()
{
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	int n, m;
	fin >> n >> m;
	fin.close();

	int k = 0;
	for (int p = 0; p <= m; p++)
		for (int q = 0; q <= m; q++)
		{
			int temp = p*p + q*q;
			if (hasExist[temp] == 0)
			{
				hasExist[temp] = 1;
				bisquare[k++] = temp;
			}
		}

	sort(bisquare, bisquare + k);

	int validCnt = 0;

	for (int gap = 1; gap <= 2 * m*m / (n - 1); gap++)
	{
		for (int i = 0; i < k; i++)
		{
			if (bisquare[i] + (n - 1)*gap>bisquare[k - 1])
				break;
			else if (i + n - 1 >= k)
				break;
			else
			{
				int cnt = 0;
				int j = 0;
				while (i + j < k)
				{
					if (bisquare[i + j] - bisquare[i] == cnt*gap)
					{
						cnt++;
						if (cnt == n)
							break;
					}
					j++;
				}
				if (cnt == n)
				{
					fout << bisquare[i] << ' ' << gap << endl;
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
