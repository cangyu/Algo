/*
ID: yhcy1991
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

long long f[10005] = { 0 };//�����ݿ��ܻ����
long long coinage[30] = { 0 };

int main(int argc, char **argv)
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int v, n;
	cin >> v >> n;
	for (int i = 1; i <= v; i++)
		cin >> coinage[i];

	f[0] = 1;
	for (int i = 1; i <= v; i++)//�п�����ʼ�Ļ��Ҿͱ�total value�󣬲���Ԥ�ȼٶ���step1 fȫΪ1
		for (int j = coinage[i]; j <= n; j++)//�Ӹ��ֻ��������ֵ����
			f[j] += f[j - coinage[i]];

	cout << f[n] << endl;
	return 0;
}
