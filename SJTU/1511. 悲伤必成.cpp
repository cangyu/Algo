// ע�⸡������ʹ�ã����ⱻ������������Ͷ�error

#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	double ans = 0;
	for (int i = 0; i < n; i++)
		ans += (i % 2 == 0 ? 1.0 / (2 * i + 1)*4.0 : -1.0 / (2 * i + 1)*4.0);

	cout << ans;

	//system("pause");
	return 0;
}
