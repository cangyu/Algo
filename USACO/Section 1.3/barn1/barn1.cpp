/*
ID: yhcy1991
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool gapCmp(int a, int b)
{
	return a > b;
}

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int m, s, c;
	fin >> m >> s >> c;
	vector<int> stalls(c);
	for (int i = 0; i < c; i++)
		fin >> stalls[i];

	sort(stalls.begin(), stalls.end());
	int sum = stalls[stalls.size() - 1] - stalls[0] + 1;

	vector<int> gaps;
	for (int i = 0; i < stalls.size()-1; i++)
	{
		if (stalls[i + 1] != stalls[i])
			gaps.push_back(stalls[i + 1] - stalls[i] - 1);
	}

	sort(gaps.begin(), gaps.end(),gapCmp);

	int cnt_boards = min(m - 1, c - 1);//注意最后木板数量的选择
	
	for (int i = 0; i < cnt_boards; i++)
		sum -= gaps[i];
	
	fout << sum << endl;

	fin.close();
	fout.close();
	return 0;
}