/*
ID: yhcy1993
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<vector>

using namespace std;

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int np;
	fin >> np;
	vector<string> name(np);
	map<string, int> givers;
	for (int i = 0; i < np; i++)
	{
		fin >> name[i];
		givers.insert(pair<string,int>(name[i], 0));
	}
	for (int i = 0; i < np; i++)
	{
		string cur_giver;
		fin >> cur_giver;
		int sum, num;
		fin >> sum >> num;
		if (num == 0)
			continue;
		int single_profit = sum / num;
		givers[cur_giver] -= (single_profit*num);
		for (int j = 0; j < num; j++)
		{
			string cur_receiver;
			fin >> cur_receiver;
			givers[cur_receiver] += single_profit;
		}
	}
	for (int i = 0; i < np; i++)
		fout << name[i] << ' ' << givers[name[i]] << endl;

	fin.close();
	fout.close();

	return 0;
}