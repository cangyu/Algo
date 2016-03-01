//不定多组数据的输入
//">>"返回其左操作数，即cin，当读取到EOF时终止while，cin本身是对象，不存在返回一说

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double CalcArea(double r, double a);

int main(int argc, char **argv)
{
	double r, a, ans, max = 0;
	while (cin >> r >> a)
	{
		ans = CalcArea(r, a);
		if (ans > max)
			max = ans;
	}
	cout << fixed << setprecision(2) << max << endl;

	//system("pause");
	return 0;
}

double CalcArea(double r, double a)
{
	double theta = acos(2 * (a / r)*(a / r) - 1);
	double ans = r*r*theta / 2 - a*sqrt(r*r - a*a);
	return ans;
}
