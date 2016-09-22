#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

//#define USE_BASIC_SELECT
#define USE_RANDOM_SELECT
//#define USE_LINEAR_SELECT

/* 按快排的思想在线性期望时间内选到第k大的元素 */
template<typename T>
T random_select(vector<T> &a, int left, int right, int k) //[,)
{
	assert(left >= 0);
	assert(left < right);
	assert(k >= 1 && k <= (right - left));

	int mid = random_partition(a, left, right);
	int leftCnt = mid - left + 1;
	if (k < leftCnt)
		return random_select(a, left, mid, k);
	else if (k > leftCnt)
		return random_select(a, mid + 1, right, k - leftCnt);
	else
		return a[mid];
}

template<typename T>
int random_partition(vector<T> &a, int left, int right) //[,)
{
	srand(time(NULL));
	int i = left + rand() % (right - left);
	T x = a[i];

	return partition(a, left, right, x);
}

template<typename T>
int partition(vector<T> &a, int left, int right, const T &pivot) //[,)
{
	for (;;)
	{
		while (a[left] < pivot) ++left;
		do{ --right; } while (pivot < a[right]);

		if (left >= right)
			return left;

		swap(a[left], a[right]);
		++left;
	}
}

/* 最坏情况下O(n)选出第k大元素 */
template<typename T>
void bubble(vector<T> &a, int left, int right)//将较小的元素冒到最左,[)形式
{
	for (int i = right - 1; i >= left + 1; i--)
	{
		if (a[i] < a[i - 1])
			swap(a[i], a[i - 1]);
	}
}

template<typename T>
void insert_sort(vector<T> &a, int left, int right)
{
	for (int i = left + 1; i < right; i++)
	{
		T curVal = a[i];
		if (curVal < a[left])
		{
			for (int j = i - 1; j >= left; --j)
				a[j + 1] = a[j];
			a[left] = curVal;
		}
		else
		{
			int j = i - 1;
			while (curVal < a[j])
			{
				a[j + 1] = a[j];
				--j;
			}
			a[j + 1] = curVal;
		}
	}
}

template<typename T>
T select(vector<T> &a, int left, int right, int k)
{
	if (right - left <= 5)
	{
		insert_sort(a, left, right);
		return a[left + k - 1];
	}

	const int grp_num = (right-left) / 5;

	for (int i = 0; i < grp_num; i++)
	{
		int start = left + 5 * i;
		int end = start + 4;

		for (int j = 0; j < 3; j++)
			bubble(a, start + j, end);

		swap(a[left + i], a[start + 2]);
	}

	T x = select(a, left, left + grp_num, grp_num / 2 + 1);//偶数取偏后一个元素
	int mid = partition(a, left, right, x);
	int leftCnt = mid - left + 1;
	if (k <= leftCnt)
		return select(a, left, mid + 1, k);
	else
		return select(a, mid + 1, right, k - leftCnt);
}

/* Solve */
int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n = 0;
	while (cin>>n)
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

#ifdef USE_BASIC_SELECT
		sort(C.begin(), C.end());//先排序再取中位数，最简单
		long long x0 = C[n / 2];
#elif defined USE_RANDOM_SELECT
		long long x0 = random_select(C, 0, n, n / 2);//随机选择pivot来划分
#elif defined USE_LINEAR_SELECT
		long long x0 = select(C, 0, n, n / 2);//线性时间选择中位数
#else
		printf("Please specify selection method!\n");
		return(-1);
#endif

		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += abs(x0 - C[i]);//转化成数学问题，数轴上绝对值和最小

		cout << ans << endl;
	}
	
	return 0;
}
