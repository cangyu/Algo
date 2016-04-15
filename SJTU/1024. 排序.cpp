#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

/*直接插入排序*/
template<typename T>
void simpleInsertSort(T a[], int len)
{
	for (int i = 1; i < len; i++)
	{
		T tmp = a[i];

		int k = i - 1;
		while (k >= 0 && a[k] >= tmp)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = tmp;
	}
}

/*希尔排序*/
template<typename T>
void shellSort(T a[], int len)
{
	for (int step = len / 2; step > 0; step /= 2)
	{
		for (int i = step; i < len; i++)
		{
			T tmp = a[i];
			int j = i - step;//该子序列的前一个，从后往前找
			while (j >= 0 && a[j] >= tmp)
			{
				a[j + step] = a[j];
				j -= step;
			}
			a[j + step] = tmp;
		}
	}
}

/*直接选择排序*/
template<typename T>
void simpleSelectSort(T a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[min_index])
				min_index = j;
		}
		T tmp = a[i];a[i] = a[min_index];a[min_index] = tmp;
	}
}

/*堆排序*/
template<typename T>
void heapSort(T a[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		percolateDown(a, i, size);

	for (int i = size - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		percolateDown(a, 0, i);
	}
}

template<typename T>
void percolateDown(T a[], int hole, int size)
{
	int child = hole * 2 + 1;
	T tmp = a[hole];

	while (child < size)
	{
		if (child != size - 1 && a[child + 1]>a[child])
			child++;
		if (a[child] > tmp)
			a[hole] = a[child];
		else
			break;
		hole = child;
		child = 2 * hole + 1;
	}
	a[hole] = tmp;
}

/*冒泡排序*/
template<typename T>
void bubbleSort(T a[], int size)
{
	for (int i = 0; i < size - 1; i++)//i表示已排好的元素的个数
	{
		bool flag = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j + 1], a[j]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

/*快速排序*/
template<typename T>
void quickSort(T a[], int size)
{
	quickSort(a, 0, size - 1);
}

template<typename T>
void quickSort(T a[], int left, int right)
{
	if (left >= right)
		return;

	int mid = partition(a, left, right);
	quickSort(a, left, mid - 1);
	quickSort(a, mid + 1, right);
}

template<typename T>
int partition(T a[], int left,int right)
{
	T pivot = a[right];
	
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (a[j] < pivot)
			swap(a[++i], a[j]);
	}
	swap(a[++i], a[right]);
	return i;	
}

/*归并排序(递归)*/
template<typename T>
void mergeSort(T a[], int size)
{
	mergeSort(a, 0, size - 1);
}

template<typename T>
void mergeSort(T a[], int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, mid, right);
}

template<typename T>
void merge(T a[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;
	T *tmp = new T[right - left + 1];

	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}

	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= right)
		tmp[k++] = a[j++];

	memcpy(a + left, tmp, k*sizeof(T));

	delete[] tmp;
}

/*归并排序(迭代)*/
template<typename T>
void mergeSort_iterative(T a[], int size)
{
	T *tmp = new T[size];

	mergeSort_iterative(a, 0, size - 1, tmp);

	delete[] tmp;
}

template<typename T>
void mergeSort_iterative(T a[], int left, int right, T tmp[])
{
	const int total = right - left + 1;
	int segmentLen = 1;
	while (segmentLen < total)
	{
		mergeNeighbors(a, left, right, segmentLen, tmp);
		segmentLen *= 2;
		mergeNeighbors(tmp, left, right, segmentLen, a);
		segmentLen *= 2;
	}
}

template<typename T>
void mergeNeighbors(T src[], int left, int right, int segLen, T dst[])
{
	int i = left;
	while (i <= right - 2 * segLen + 1)//若最后恰好剩下2*segLen个数也进行merge
	{
		merge(src, i, i + segLen - 1, i + 2 * segLen - 1, dst);
		i += 2 * segLen;
	}

	if (i + segLen <= right)
		merge(src, i, i + segLen - 1, right, dst);//注意要写dst
	else
		memcpy(dst + i, src + i, (right - i + 1)*sizeof(T));
}

template<typename T>
void merge(T src[], int left, int mid, int right, T dst[])
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (src[i] < src[j])
			dst[k++] = src[i++];
		else
			dst[k++] = src[j++];
	}

	while (i <= mid)
		dst[k++] = src[i++];
	while (j <= right)
		dst[k++] = src[j++];
}

/*原地归并(递归)*/
template<typename T>
void mergeSort_inplace(T a[], int size)
{
	mergeSort_inplace(a, 0, size - 1);
}

template<typename T>
void mergeSort_inplace(T a[], int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort_inplace(a, left, mid);
	mergeSort_inplace(a, mid + 1, right);
	merge_inplace(a, left, mid, right);
}

template<typename T>
void merge_inplace(T a[], int left, int mid, int right)
{
	int i = left, j = mid + 1;
	while (i < j && j <= right)
	{
		while (i < j && a[i] <= a[j]) i++;
		int index = j;
		while (j <= right && a[j] <= a[i]) j++;
		swapBlock(a, i, index, j);//here is 0-based 
		i += (j - index);
	}
}

template<typename T>
void swapBlock(T a[], int begin, int mid, int end)
{
	reverse(a + begin, a + mid);
	reverse(a + mid, a + end);
	reverse(a + begin, a + end);
}

/*原地归并(迭代)*/
template<typename T>
void mergeSort_inplace_iterative(T a[], int size)
{
	mergeSort_inplace_iterative(a, 0, size - 1);
}

template<typename T>
void mergeSort_inplace_iterative(T a[], int left, int right)
{
	const int total = right - left + 1;
	int segLen = 1;
	while (segLen < total)
	{
		mergeNeighbors_inplace(a, left, right, segLen);
		segLen *= 2;
	}
}

template<typename T>
void mergeNeighbors_inplace(T a[], int left, int right, int segLen)
{
	int i = left;
	while (i <= right - 2 * segLen + 1)
	{
		merge_inplace(a, i, i + segLen - 1, i + 2 * segLen - 1);//与上面原地归并(递归)中的一致
		i += 2 * segLen;
	}

	if (i + segLen <= right)
		merge_inplace(a, i, i + segLen - 1, right);
}


int main(int argc, char **argv)
{
	//freopen("1024_5.in", "r", stdin);
	//freopen("1024.out", "a", stdout);
	
	int n;
	scanf("%d", &n);

	int *a = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	//clock_t start, end;
	//start = clock();

	mergeSort_inplace_iterative(a, n);

	//end = clock();
	//cout << "排序 " << n << " 个随机数共花费 " << (double)(end - start) << "ms" << endl;

	
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";

	delete[] a;
	return 0;
}

/*
附本测试结果：

个人感觉二分大法好，堆也不错，快排你咋了。。。

直接插入排序：
排序 1000 个随机数共花费 0ms
排序 10000 个随机数共花费 69ms
排序 100000 个随机数共花费 6510ms

希尔排序：
排序 1000 个随机数共花费 0ms
排序 10000 个随机数共花费 0ms
排序 100000 个随机数共花费 15ms
排序 1000000 个随机数共花费 447ms
排序 10000000 个随机数共花费 14280ms
排序 100000000 个随机数共花费 941766ms

直接选择排序：
排序 1000 个随机数共花费 1ms
排序 10000 个随机数共花费 138ms
排序 100000 个随机数共花费 12986ms

堆排序：
排序 1000 个随机数共花费 0ms
排序 10000 个随机数共花费 0ms
排序 100000 个随机数共花费 31ms
排序 1000000 个随机数共花费 416ms
排序 10000000 个随机数共花费 5577ms
排序 100000000 个随机数共花费 70666ms

冒泡排序：
排序 1000 个随机数共花费 32ms
排序 10000 个随机数共花费 2903ms
排序 100000 个随机数共花费 292591ms

快排：
排序 1000 个随机数共花费 2ms
排序 10000 个随机数共花费 15ms
排序 100000 个随机数共花费 185ms
排序 1000000 个随机数共花费 1390ms
排序 10000000 个随机数共花费 17675ms
排序 100000000 个随机数共花费 547135ms

归并：
排序 1000 个随机数共花费 0ms
排序 10000 个随机数共花费 16ms
排序 100000 个随机数共花费 501ms
排序 1000000 个随机数共花费 4712ms
排序 10000000 个随机数共花费 43009ms
排序 100000000 个随机数共花费 315892ms

归并（迭代）：
排序 1000 个随机数共花费 0ms
排序 10000 个随机数共花费 0ms
排序 100000 个随机数共花费 15ms
排序 1000000 个随机数共花费 185ms
排序 10000000 个随机数共花费 2071ms
排序 100000000 个随机数共花费 21296ms

原地归并：
排序 1000 个随机数共花费 20ms
排序 10000 个随机数共花费 1970ms
排序 100000 个随机数共花费 118044ms

原地归并（迭代）：
排序 1000 个随机数共花费 15ms
排序 10000 个随机数共花费 1820ms
排序 100000 个随机数共花费 128235ms
*/