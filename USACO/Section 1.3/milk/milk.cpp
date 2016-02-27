/*
ID: yhcy1991
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct bid {
	int price;
	int amount;
}BidInfo;

bool BidCmp(const BidInfo &a, const BidInfo &b)
{
	return a.price < b.price;
}

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int n, m;
	fin >> n >> m;
	if (n == 0)
	{
		fout << 0 << endl;
		fin.close();
		fout.close();
		return 0;
	}

	vector<BidInfo> biddings(m);
	for (int i = 0; i < m; i++)
		fin >> biddings[i].price >> biddings[i].amount;

	sort(biddings.begin(), biddings.end(), BidCmp);

	long long sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (biddings[i].amount < n)
		{
			n -= biddings[i].amount;
			sum += biddings[i].amount*biddings[i].price;
		}
		else
		{
			sum += n*biddings[i].price;
			break;
		}
	}

	fout << sum << endl;

	fin.close();
	fout.close();
	return 0;
}