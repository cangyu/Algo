/*
ID: yhcy1991
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream dict("dict.txt");

	const int map[27] = { 0, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0 };

	string ori;
	fin >> ori;
	int n = ori.length();
	vector<int> oriNum(n);
	for (int i = 0; i < n; i++)
		oriNum[i] = ori[i] - '0';

	string candidate;
	bool hasFound = false;
	while (dict >> candidate)
	{
		if (candidate.length() == n)
		{
			bool isQualify = true;
			for (int i = 0; i < n; i++)
			{
				int k = candidate[i] - 'A' + 1;
				if (oriNum[i] != map[k])
				{
					isQualify = false;
					break;
				}	
			}
			if (isQualify)
			{
				fout << candidate << endl;
				hasFound = true;
			}
		}
	}
	if (!hasFound)
		fout << "NONE" << endl;

	dict.close();
	fin.close();
	fout.close();
	return 0;
}