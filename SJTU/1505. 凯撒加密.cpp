// ��д��ASCLL���ֵ��Сд��ҪС��˫���ж�

#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	char t;
	cin >> t;
	bool islower = true;
	if ('A' <= t && t <= 'Z')
		islower = false;

	if (islower)
		cout << (char)(((t - 'a' + 3) % 26) + 'a');
	else
		cout << (char)(((t - 'A' + 3) % 26) + 'A');

	//system("pause");
}
