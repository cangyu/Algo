/*
ID: yhcy1991
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool myCmp(vector<int> array1, vector<int> array2)
{
	return (array1[0] < array2[0]);
}

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	int n;
	fin >> n;
	vector<vector<int> > timetable(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++)
		fin >> timetable[i][0] >> timetable[i][1];

	sort(timetable.begin(), timetable.end(), myCmp);

	int maxWork = timetable[0][1] - timetable[0][0];
	int maxIdle = 0;
	int curWorkWindow_Start = timetable[0][0];
	int curWorkWindow_End = timetable[0][1];

	for (int i = 1; i < n; i++)
	{
		if (curWorkWindow_Start <= timetable[i][0] && timetable[i][0] <= curWorkWindow_End)
		{
			if (timetable[i][1] <= curWorkWindow_End)
				continue;
			else
			{
				curWorkWindow_End = timetable[i][1];
				int curWork = curWorkWindow_End - curWorkWindow_Start;
				maxWork = max(maxWork, curWork);
			}
		}
		else
		{
			int curIdle = timetable[i][0] - curWorkWindow_End;
			maxIdle = max(maxIdle, curIdle);
			curWorkWindow_Start = timetable[i][0];
			curWorkWindow_End = timetable[i][1];
		}
	}
	fout << maxWork << ' ' << maxIdle << endl;

	fin.close();
	fout.close();
	return 0;
}