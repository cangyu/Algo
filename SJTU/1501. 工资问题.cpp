//��ο��������ʽ���Ƿ����ݵĹ���

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	float a, b;
	cin >> a >> b;
	//cout.precision(2);
	if (a < 0 || b < 0)
		cout << 0 << " " << 0;
	else
		cout << a*b << " " << a*b*0.9;
}

