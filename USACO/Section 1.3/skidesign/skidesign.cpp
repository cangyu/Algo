/*
ID: yhcy1991
PROG: skidesign
LANG: C++
*/

//�����Ƕȿ����⣬��������������
//ö�����п��ܵĸ߶����䣬ȡ��С���ɣ������ڡ���ȥ��Ҫ���ڼ��ϵġ���ô��Ҫ��

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	int n;
	fin >> n;
	vector<int> hills(n);
	for (int i = 0; i < n; i++)
		fin >> hills[i];

	int minCost = 0;
	int left = 0, right = 17;
	for (int i = 0; i < n; i++)
	{
		if (hills[i] < left)
			minCost += (left - hills[i])*(left - hills[i]);
		else if (hills[i]>right)
			minCost += (hills[i] - right)*(hills[i] - right);
		else
			continue;
	}

	for (left = 1; left <= 83; left++)
	{
		right = left + 17;
		int curCost = 0;
		for (int i = 0; i < n; i++)
		{
			if (hills[i] < left)
				curCost += (left - hills[i])*(left - hills[i]);
			else if (hills[i]>right)
				curCost += (hills[i] - right)*(hills[i] - right);
			else
				continue;
		}
		minCost = min(minCost, curCost);
	}

	fout << minCost << endl;

	fin.close();
	fout.close();
	return 0;
}