/*
ID: yhcy1991
PROG: crypt1
LANG: C++
*/

//穷举，构造简单的hash表来检测数位

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isQualify(int num, const int *ref)
{
	while (num)
	{
		int tmp = num % 10;
		if (!ref[tmp])
			return false;
		num /= 10;
	}
	return true;
}

int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int n;
	fin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		fin >> nums[i];

	int t[10] = { 0 };
	for (int i = 0; i < n; i++)
		t[nums[i]] = 1;

	int cnt = 0;

	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++)
			for (int c = 0; c < n; c++)
			{
				int m1 = 100 * nums[a] + 10 * nums[b] + nums[c];
				for (int d = 0; d < n; d++)
					for (int e = 0; e < n; e++)
					{
						int m2 = 10 * nums[d] + nums[e];
						int part1 = m1*nums[e];
						if (100 < part1 && part1 < 1000 && isQualify(part1,t))
						{
							int part2 = m1*nums[d];
							if (100 < part2 && part2 < 1000 && isQualify(part2, t))
							{
								int res = m1*m2;
								if (1000 < res && res < 10000 && isQualify(res, t))
									cnt++;
							}
						}
					}
			}

	fout << cnt << endl;

	fin.close();
	fout.close();
	return 0;
}