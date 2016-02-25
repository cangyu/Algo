/*
ID: yhcy1993
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	string comet;
	string candidate;

	getline(fin, comet);
	getline(fin, candidate);

	int x1 = 1;
	for (int i = 0; i < comet.length(); i++)
		x1 *= (comet[i] - 'A' + 1);
	x1 %= 47;

	int x2 = 1;
	for (int i = 0; i < candidate.length(); i++)
		x2 *= (candidate[i] - 'A' + 1);
	x2 %= 47;

	if (x1 == x2)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;

	return 0;
}