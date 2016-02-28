#include<iostream>
#include<iomanip>

using namespace std;

//参考Linux中的mktime()的算法
int gapAbsolute(int y, int m, int d)//距离公元1年1月1日的天数（其实这天还是星期一）
{
	m -= 2;
	if (m <= 0)
		m += 12, y--;

	int part1 = (y - 1) * 365;
	int part2 = y / 4 - y / 100 + y / 400;
	int part3 = 367 * m / 12 - 30; //到该月(m)已经过去的天数，从这年的1月1日算起（新坐标系下）
	int part4 = d - 1 + 59;

	return part1 + part2 + part3 + part4;
}

int gapBetween(int y1, int m1, int d1, int y2, int m2, int d2)//从date1到date2需要经过的天数
{
	m1 -= 2, m2 -= 2;
	if (m1 <= 0)
		m1 += 12, y1--;
	if (m2 <= 0)
		m2 += 12, y2--;

	int p1 = 367 * m1 / 12 - 30 + d1;
	int p2 = (y2 - y1) * 365;
	int p3 = 367 * m2 / 12 - 30 + d2;
	int p4 = (y2 / 4 - y2 / 100 + y2 / 400) - (y1 / 4 - y1 / 100 + y1 / 400);
	return p2 - p1 + p3 + p4;//[...]-[...]+[...]=(...]+[...]=(...],刚好
}

bool isLeapYear(int y)
{
	return (y % 4 == 0 && (y % 100 || y % 400 == 0));//命题逻辑中的蕴含式的应用
}

int daysInYear[13] = { 366, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(int argc, char** argv)
{
	int a, b, c, y1, y2;
	cin >> a >> b >> c >> y1 >> y2;

	
	for (int i = y1; i <= y2; i++)
	{
		int gap = gapBetween(1850, 1, 1, i, a, 1);
		int weekday = (2 + gap % 7) % 7;
		if (weekday == 0)
			weekday = 7;

		int firstgap = c - weekday;
		if (firstgap < 0)
			firstgap += 7;

		int steps = firstgap + (b - 1) * 7;
		if (isLeapYear(i))
			daysInYear[2] = 29;

		if (steps + 1>daysInYear[a])
			cout << "none" << endl;
		else
		{
			cout << setfill('0');
			cout << setw(4) << i << setw(1) << "/" << setw(2) << a << setw(1) << "/" << setw(2) << steps + 1 << endl;
		}
	}

	//system("pause");
	return 0;
}
