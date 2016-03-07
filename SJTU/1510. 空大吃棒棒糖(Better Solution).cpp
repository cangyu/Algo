//O(1) solution, ref to java localdate add()

#include<iostream>

using namespace std;

const int DAYS_PER_CYCLE = 146097;//days in per 400 years

typedef struct
{
	int year;
	int month;
	int day;
} DateTypeDef, *pDataTypeDef;

int calcDate(pDataTypeDef input, int n, pDataTypeDef output);
int getDaysFrom0000_01_01(pDataTypeDef date);
int showDate(pDataTypeDef date);

int main(int argc, char **argv)
{
	DateTypeDef originDate, res1, res2;
	cin >> originDate.year >> originDate.month >> originDate.day;

	calcDate(&originDate, 10000, &res1);
	calcDate(&originDate, 20000, &res2);

	showDate(&res1);
	showDate(&res2);
	
	//system("pause");
	return 0;
}

int calcDate(pDataTypeDef input, int n, pDataTypeDef output)
{
	long long totalDays = getDaysFrom0000_01_01(input) + n;
	
	//find the march-based year
	totalDays -= 60;//convert to march-based coordinate
	int adjustYears = 0;
	if (totalDays < 0)
	{
		long long adjustCycles = (totalDays + 1) / DAYS_PER_CYCLE - 1;
		adjustYears = adjustCycles * 400;
		totalDays += -adjustCycles * 400;
	}
	long long yearEst = (400 * totalDays + 591) / DAYS_PER_CYCLE;//Estimation of the march-based year
	int doyEst = totalDays - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);//day of year in the march-based year
	if (doyEst < 0)
	{
		yearEst--;
		doyEst = totalDays - (365 * yearEst + yearEst / 4 - yearEst / 100 + yearEst / 400);
	}
	yearEst += adjustYears;//reset any negative year
	
	int marchDoy0 = (int)doyEst;

	//convert march-based values back to january-based
	int marchMonth0 = (marchDoy0 * 5 + 2) / 153;
	int month = (marchMonth0 + 2) % 12 + 1;
	int dom = marchDoy0 - (marchMonth0 * 306 + 5) / 10 + 1;
	yearEst += marchMonth0 / 10;
	int year = yearEst;
	
	output->year = year, output->month = month, output->day = dom;
	return 0;
}

int getDaysFrom0000_01_01(pDataTypeDef date)
{
	int y = date->year, m = date->month, d = date->day;
	m -= 2;
	if (m <= 0)
	{
		m += 12;
		y--;
	}
	int part1 = 365 * (y - 1) + y / 4 - y / 100 + y / 400;
	int part2 = 367 * m / 12 - 30 + d - 1;

	return 59 + part1 + part2 + 366;
}

int showDate(pDataTypeDef date)
{
	cout << date->year << " " << date->month << " " << date->day << endl;
	return 0;
}