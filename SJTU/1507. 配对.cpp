//����֤����������ǽ�a�е���С��b�е������ԣ������a[i]<a[j]��b[i]>b[j],�����λ��ԣ����ܻ���gap����gap>=0 (�������ۼ���֤��)

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main(int argc, char **argv)
{
	int n;
	int a[100000], b[100000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	sort(a, a + n);
	sort(b, b + n);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (abs(a[i] - b[n - 1 - i]));

	cout << ans;
	//system("pause");
}
