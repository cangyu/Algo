//输出格式的控制：位宽，填充
//分解过程

#include<iostream>
#include<iomanip>

using namespace std;

const int daysInLeapYear[13] = { 366, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int daysInCommonYear[13] = { 365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

typedef struct
{
	int year;
	int month;
	int day;
	int weekday;
}DateTypeDef, *pDateTypedef;

void fixWeekday(pDateTypedef date, pDateTypedef ref);
bool processToTarget(pDateTypedef date, int targetIndex, int targetWeekday);
void print(pDateTypedef date);
int calcDaysGap(pDateTypedef date, pDateTypedef ref);
void goToFirstTargetWeekday(pDateTypedef date, int targetWeekday);
void goToTargetWeekdayFromFirst(pDateTypedef date, int targetIndex);
bool checkDateIsValid(pDateTypedef date);
int daysHasElapsedInTheYear(pDateTypedef date);
bool isLeapYear(int year);

int main(int argc, char **argv)
{
	int month, index, weekday, year_start, year_end;
	cin >> month >> index >> weekday >> year_start >> year_end;

	DateTypeDef ref = { 1850, 1, 1, 2 };

	for (int i = year_start; i <= year_end; i++)
	{
		DateTypeDef tmp = { i, month, 1, 0 };
		fixWeekday(&tmp, &ref);
		if (processToTarget(&tmp, index, weekday))
			print(&tmp);
		else
			cout << "none" << endl;
	}

	//system("pause");
	return 0;
}

void fixWeekday(pDateTypedef date, pDateTypedef ref)
{
	int dist = calcDaysGap(date, ref);
	int weekday_num = ref->weekday + dist % 7;
	if (weekday_num > 7)
		weekday_num -= 7;
	date->weekday = weekday_num;
}

bool processToTarget(pDateTypedef date, int targetIndex, int targetWeekday)
{
	goToFirstTargetWeekday(date, targetWeekday);
	goToTargetWeekdayFromFirst(date, targetIndex);
	if (checkDateIsValid(date))
		return true;
	else
		return false;
}

void print(pDateTypedef date)
{
	cout << setfill('0');
	cout << setw(4) << date->year
		<< setw(1) << "/"
		<< setw(2) << date->month
		<< setw(1) << "/"
		<< setw(2) << date->day
		<< endl;
}

int calcDaysGap(pDateTypedef date, pDateTypedef ref)
{
	int ans = 0;
	int year_start = ref->year;
	int year_end = date->year;

	for (int i = year_start; i < year_end; i++)
	{
		if (isLeapYear(i))
			ans += 366;
		else
			ans += 365;
	}

	int n1 = daysHasElapsedInTheYear(ref);
	int n2 = daysHasElapsedInTheYear(date);

	ans -= (n1 + 1);
	ans += (n2 + 1);

	return ans;
}

void goToFirstTargetWeekday(pDateTypedef date, int targetWeekday)
{
	int dist = targetWeekday - date->weekday;
	if (dist < 0)
		dist += 7;
	date->day += dist;
	date->weekday = targetWeekday;
}

void goToTargetWeekdayFromFirst(pDateTypedef date, int targetIndex)
{
	int dist = (targetIndex - 1) * 7;
	date->day += dist;
}

bool checkDateIsValid(pDateTypedef date)
{
	if (date->year < 1850)
		return false;
	if (date->month < 0 || date->month>12)
		return false;
	if (date->day < 0)
		return false;
	if (isLeapYear(date->year))
	{
		if (date->day > daysInLeapYear[date->month])
			return false;
	}
	else
	{
		if (date->day > daysInCommonYear[date->month])
			return false;
	}

	if (date->weekday < 1 || date->weekday>7)
		return false;

	return true;
}

int daysHasElapsedInTheYear(pDateTypedef date)
{
	int ans = 0;
	if (isLeapYear(date->year))
	{
		for (int i = 1; i < date->month; i++)
			ans += daysInLeapYear[i];
		ans += date->day - 1;
	}
	else
	{
		for (int i = 1; i < date->month; i++)
			ans += daysInCommonYear[i];
		ans += date->day - 1;
	}
	return ans;
}

bool isLeapYear(int year)
{
	if (year % 100 != 0)
	{
		if (year % 4 == 0)
			return true;
		else
			return false;
	}
	else
	{
		if (year % 400 == 0)
			return true;
		else
			return false;
	}
}
