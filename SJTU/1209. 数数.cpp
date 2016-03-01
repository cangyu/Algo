//二分法，逐步增加步长并累计

#include<iostream>

using namespace std;

int CalcNbrOfOne(int t);

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	int ans = 0;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		ans += CalcNbrOfOne(t);
	}
	cout << ans << endl;

	//system("pause");

	return 0;
}

int CalcNbrOfOne(int t)
{
	int num = t;
	num = (num & 0x55555555) + ((num & 0xAAAAAAAA) >> 1);
	num = (num & 0x33333333) + ((num & 0xCCCCCCCC) >> 2);
	num = (num & 0x0F0F0F0F) + ((num & 0xF0F0F0F0) >> 4);
	num = (num & 0x00FF00FF) + ((num & 0xFF00FF00) >> 8);
	num = (num & 0x0000FFFF) + ((num & 0xFFFF0000) >> 16);
	return num;
}
