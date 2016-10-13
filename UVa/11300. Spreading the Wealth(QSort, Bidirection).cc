#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

template<typename T>
T find_Kth(vector<T> &a, int left, int right, int k);
template<typename T>
int random_partition(vector<T> &a, int left, int right);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	srand(time(NULL));

	int n = 0;
	while (cin >> n)
	{
		vector<long long> C(n);

		long long sum = 0, cur = 0;
		C[0] = 0;
		cin >> sum;

		for (int i = 1; i < n; i++)
		{
			C[i] = sum;
			cin >> cur;
			sum += cur;
		}

		long long M = sum / n;
		for (int i = 1; i < n; i++)
			C[i] -= i*M;

		long long x0 = find_Kth(C, 0, C.size() - 1, n / 2 + 1);

		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += abs(x0 - C[i]);//转化成数学问题，数轴上绝对值和最小

		cout << ans << endl;
	}

	return 0;
}

template<typename T>
T find_Kth(vector<T> &a, int left, int right, int k)//[,]
{
	int mid = random_partition(a, left, right + 1);
	int leftCnt = mid - left + 1;

	if (k < leftCnt)
		return  find_Kth(a, left, mid - 1, k);
	else if (k > leftCnt)
		return find_Kth(a, mid + 1, right, k - leftCnt);
	else
		return a[mid];
}

//随机化分割一个线性表
//[,)形式,双向扫描
//本题中和单向扫描差别不大
template<typename T>
int random_partition(vector<T> &a, int left, int right)
{
	if (left >= right)
		return left;

	int pivot_index = left + rand() % (right - left);
	swap(a[left], a[pivot_index]);

	int i = left, j = right;
	for (;;)
	{
		while (a[--j] > a[left]);
		while (a[++i] < a[left]);

		if (i >= j)
			break;

		swap(a[i], a[j]);
	}
	swap(a[left], a[j]);
	return j;
}
