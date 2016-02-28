//Öð²½·Ö½â

#include<iostream>

using namespace std;

typedef struct
{
	int year;
	int month;
	int day;
} DateTypeDef, *pDataTypeDef;

int calcDate(pDataTypeDef input, int n, pDataTypeDef output);
int showDate(pDataTypeDef date);
bool isLeapYear(int year);
int increaseYear(pDataTypeDef date);
int decreaseOneDay(pDataTypeDef date);
int calcDaysLeftToYearEnd(pDataTypeDef date);
int calcDaysLeftToMonthEnd(pDataTypeDef date);

const int daysInLeapYear[13] = { 366, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int daysInCommonYear[13] = { 365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(int argc, char **argv)
{
	DateTypeDef originDate, res1, res2;
	cin >> originDate.year >> originDate.month >> originDate.day;

	calcDate(&originDate, 10000, &res1);
	calcDate(&originDate, 20000, &res2);

	showDate(&res1);
	cout << endl;
	showDate(&res2);
	//system("pause");

	return 0;
}

int showDate(pDataTypeDef date)
{
	cout << date->year << " " << date->month << " " << date->day << endl;
	return 0;
}

int calcDate(pDataTypeDef input, int n, pDataTypeDef output)
{
	output->year = input->year;
	output->month = input->month;
	output->day = input->day;

	while (n >= 365)
	{
		n -= 365;
		if (isLeapYear(output->year))
		{
			increaseYear(output);
			if (output->month < 3)
				decreaseOneDay(output);
		}
		else
		{
			if (isLeapYear(output->year + 1))
			{
				increaseYear(output);
				if (output->month >= 3)
					decreaseOneDay(output);
			}
			else
				increaseYear(output);
		}
	}

	const int daysToYearEnd = calcDaysLeftToYearEnd(output);
	if (n > daysToYearEnd)
	{
		n -= (daysToYearEnd + 1);
		output->year++;
		output->month = 1;
		output->day = 1;
	}

	int daysToMonthEnd = 0;

	while (n > (daysToMonthEnd = calcDaysLeftToMonthEnd(output)))
	{
		n -= (daysToMonthEnd + 1);
		output->month++;
		output->day = 1;
	}

	output->day += n;

	return 0;
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

int increaseYear(pDataTypeDef date)
{
	date->year += 1;
	return 0;
}

int decreaseOneDay(pDataTypeDef date)
{
	if (date->day == 1)
	{
		if (date->month == 1)
		{
			date->year--;
			date->month = 12;
			date->day = 31;
		}
		else
		{
			date->month--;
			if (isLeapYear(date->year))
				date->day = daysInLeapYear[date->month];
			else
				date->day = daysInCommonYear[date->month];
		}
	}
	else
		date->day--;

	return 0;
}

int calcDaysLeftToYearEnd(pDataTypeDef date)
{
	int ans = calcDaysLeftToMonthEnd(date);
	int m = date->month + 1;
	if (isLeapYear(date->year))
	{
		for (int i = m; i <= 12; i++)
			ans += daysInLeapYear[i];
	}
	else
	{
		for (int i = m; i <= 12; i++)
			ans += daysInCommonYear[i];
	}

	return ans;
}

int calcDaysLeftToMonthEnd(pDataTypeDef date)
{
	int ans = 0;

	if (isLeapYear(date->year))
		ans = daysInLeapYear[date->month] - date->day;
	else
		ans = daysInCommonYear[date->month] - date->day;

	return ans;
}
