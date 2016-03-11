//����ͼ�������Էֿ�������֤ƫ���ϵ�Ŀɴ����ԣ��������������򲻸���
//u64,s64�����������printf��scanf��ʹ��

#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>

using namespace std;

typedef unsigned long long int u64;
typedef long long int s64;

void count_reverse(s64 *a, int left, int right, u64 &cnt, s64 *tmp);
void merge_count(s64 *a, int left, int mid, int right, u64 &cnt, s64 *tmp);

int main(int argc, char** argv)
{
	int n;
	scanf("%d", &n);
	s64 *a = new s64[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	u64 reverse_cnt = 0;
	s64 *tmp = new s64[n];
	count_reverse(a, 0, n - 1, reverse_cnt, tmp);

	printf("%llu", reverse_cnt);

	delete[] a;
	delete[] tmp;

	//system("pause");

	return 0;
}

void count_reverse(s64 *a, int left, int right, u64 &cnt, s64 *tmp)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		count_reverse(a, left, mid, cnt, tmp);
		count_reverse(a, mid + 1, right, cnt, tmp);
		merge_count(a, left, mid, right, cnt, tmp);
	}
}

void merge_count(s64 *a, int left, int mid, int right, u64 &cnt, s64 *tmp)
{
	//������
	int i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (a[i]>2 * a[j])
		{
			cnt += (mid - i + 1);
			j++;
		}
		else
			i++;
	}

	i = left, j = mid + 1;
	int k = left;
	//��ɨһ�飬��������Ӱ�츴�ӶȵĽף�
	while (i <= mid && j <= right)
	{
		if (a[i] > a[j])
			tmp[k++] = a[j++];
		else
			tmp[k++] = a[i++];
	}
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= right)
		tmp[k++] = a[j++];

	for (k = left; k <= right; k++)
		a[k] = tmp[k];
}
