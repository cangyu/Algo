#include <iostream>
#include <iomanip>
#include <cmath>

//�򵥵�������������������Ҫ��ֹ�ӷ��Ĺ�����������𲽼��������ע����������
//�����ʽ����

using namespace std;

int main(int argc, char **argv)
{
	float result = 0;
	int residue[4];
	int integer[4];
	int res_sum = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> integer[i];
		residue[i] = integer[i] % 4;
		res_sum += residue[i];
		integer[i] -= residue[i];
		integer[i] /= 4;
		result += integer[i];
	}
	if (res_sum % 4 == 0)
		cout << result + res_sum / 4;
	else if (abs(res_sum % 4) == 2)
	{
		float r = res_sum;
		r /= 4;
		r += result;
		cout.precision(1);
		cout << fixed << r;
	}
	else
	{
		float r = res_sum;
		r /= 4;
		r += result;
		cout.precision(2);
		cout << fixed << r;
	}
}
