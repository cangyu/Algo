#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//��Ȼ���ˣ��������ַ������ʺϴ������п����ڼ���ƽ���Ĺ����в������

int main(int argc, char **argv)
{
	double t[4];
	for (int i = 0; i < 4; i++)
		cin >> t[i];
	double dist = sqrt((t[0] - t[2])*(t[0] - t[2]) + (t[1] - t[3])*(t[1] - t[3]));
	//cout.precision(5);
	//cout << fixed << dist;
	cout << dist;

	//system("pause");
}
