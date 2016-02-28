//Important������ʱ������ĳһ�������ڼ����㷨��Linux�е�mktime��
//β��ϸ�ڴ����������������㷨
//ѭ����ƣ����ⲻ��Ҫ������
//���ڵ����ã������+1���

#include<iostream>

using namespace std;

void CalcTradingDays(int year_start, int month_start, int day_start, int year_end, int month_end, int day_end);
int DayOfWeek(int y, int m, int d);
int DaysElapsedSinceBeginningEra(int y, int m, int d);
void GoToPreviousDay(int *y, int *m, int *d);
bool isLeapYear(int year);
void GoToNextSpecialDay(int *y, int *m, int *d);
bool isInsideTheRange(int y, int m, int d, int ye, int me, int de);

int main(int argc, char **argv)
{
	int n;
	cin >> n;

	int year_start, month_start, day_start;
	int year_end, month_end, day_end;
	char a;

	for (int i = 0; i < n; i++)
	{
		cin >> year_start >> a >> month_start >> a >> day_start;
		cin >> year_end >> a >> month_end >> a >> day_end;

		CalcTradingDays(year_start, month_start, day_start, year_end, month_end, day_end);

		if (i != n - 1)
			cout << endl;
	}
	//system("pause");
	return 0;
}

void CalcTradingDays(int year_start, int month_start, int day_start, int year_end, int month_end, int day_end)
{

	int dayOfWeek_Start = DayOfWeek(year_start, month_start, day_start);
	int dayOfWeek_End = DayOfWeek(year_end, month_end, day_end);
	int gap = DaysElapsedSinceBeginningEra(year_end, month_end, day_end) - DaysElapsedSinceBeginningEra(year_start, month_start, day_start) + 1;

	//ȥ��������ĩ
	int weeks = gap / 7;
	int ans = gap - weeks * 2;
	//β������
	int residue = gap - weeks * 7;
	int i = dayOfWeek_Start;//�˴�i����Ҫ��������һ����7����ǳ�ʼ������
	while (residue > 0)
	{
		if (i >= 6)
			ans--;
		//move to next day
		i++;
		i %= 7;
		if (i == 0)
			i = 7;
		residue--;
	}

	//ȥ�����������
	int y = year_start, m = month_start, d = day_start;
	GoToPreviousDay(&y, &m, &d);
	GoToNextSpecialDay(&y, &m, &d);
	while (isInsideTheRange(y, m, d, year_end, month_end, day_end))
	{
		if (DayOfWeek(y, m, d) < 6)
			ans--;
		GoToNextSpecialDay(&y, &m, &d);
	}

	cout << ans;
}

int DayOfWeek(int y, int m, int d)
{
	//����X�ᣬ��2�µ����һ�쵱��һ������һ��
	m -= 2;
	if (m <= 0)
	{
		m += 12;
		y--;
	}
	int dayofweek = 1;
	dayofweek += (y - 1 + y / 4 - y / 100 + y / 400 + 367 * m / 12 - 30 + 59 + d - 1) % 7;
	if (dayofweek > 7)
		dayofweek -= 7;

	return dayofweek;
}

int DaysElapsedSinceBeginningEra(int y, int m, int d)
{
	m -= 2;
	if (m <= 0)
	{
		m += 12;
		y--;
	}
	//������㷨���ֲ��ۼ�
	return (y - 1) * 365 + y / 4 - y / 100 + y / 400 + 59 + 367 * m / 12 - 30 + d - 1;
}

const int daysInLeapYear[13] = { 366, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int daysInCommonYear[13] = { 365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


void GoToPreviousDay(int *y, int *m, int *d)
{
	if (*d != 1)
		*d -= 1;
	else
	{
		if (*m != 1)
		{
			*m -= 1;
			*d = isLeapYear(*y) ? daysInLeapYear[*m] : daysInCommonYear[*m];
		}
		else
		{
			*y -= 1;
			*m = 12;
			*d = isLeapYear(*y) ? daysInLeapYear[*m] : daysInCommonYear[*m];
		}
	}
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

void GoToNextSpecialDay(int *y, int *m, int *d)
{
	if (*m < 5)
		*m = 5, *d = 1;
	else if (*m == 5)
	{
		if (*d < 3)
			*d += 1;
		else
			*m = 10, *d = 1;
	}
	else if (*m < 10)
		*m = 10, *d = 1;
	else if (*m == 10)
	{
		if (*d < 7)
			*d += 1;
		else
			*y += 1, *m = 1, *d = 1;
	}
	else
		*y += 1, *m = 1, *d = 1;
}

bool isInsideTheRange(int y, int m, int d, int ye, int me, int de)
{
	if (y < ye)
		return true;
	else if (y == ye)
	{
		if (m < me)
			return true;
		else if (m == me)
		{
			if (d <= de)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
