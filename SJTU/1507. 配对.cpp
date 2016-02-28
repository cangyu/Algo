//可以证明，如果不是将a中的最小和b中的最大配对，则对于a[i]<a[j]和b[i]>b[j],如果错位配对，则总会有gap，且gap>=0 (分类讨论即可证明)

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
