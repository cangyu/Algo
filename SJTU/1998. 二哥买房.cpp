//逐步分析出规律

#include<iostream>

using namespace std;

void myQsort(int *nums, int left, int right);
int partition(int *nums, int left, int right);
inline void swap(int *nums, int i, int j);

int main(int argc, char** argv)
{
	int n;
	cin >> n;

	int* places = new int[n];

	for (int i = 0; i < n; i++)
		cin >> places[i];

	myQsort(places, 0, n);

	int ans = 0;
	int i = 0, j = n - 1;
	while (i < j)
		ans += (places[j--] - places[i++]);

	cout << ans << endl;
	delete[]places;

	//system("pause");

	return 0;
}

void myQsort(int *nums, int left, int right)
{
	if (left < right)
	{
		int mid = partition(nums, left, right);
		myQsort(nums, left, mid);
		myQsort(nums, mid + 1, right);
	}
}

int partition(int *nums, int left, int right)
{
	int x = nums[right - 1];
	int i = left - 1, j = left;
	while (j < right)//j始终对应待处理元素，i对应最后一个被处理的小于x的元素	
	{
		if (nums[j] < x)
		{
			i++;
			swap(nums, i, j);
		}
		j++;
	}
	i++;
	swap(nums, i, right - 1);
	return i;
}

inline void swap(int *nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}
