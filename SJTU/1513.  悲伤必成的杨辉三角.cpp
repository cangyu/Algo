// 注意递归的边界条件，避免重复计算
// 还可以再减少空间，逐层迭代，这样空间复杂度只有O(N)，但转换过程略复杂

#include<iostream>

using namespace std;

typedef long long unsigned int u64;

const int MAX_LEVEL = 50;
const int MAX_NUM = MAX_LEVEL*(MAX_LEVEL + 1) / 2;

u64 triangleMatrix[MAX_NUM] = { 0 };

//对杨辉三角的计取方式为：第n行，第i个（n与i从1开始）。
inline int getIndex(int n, int i)
{
	return n*(n - 1) / 2 + i - 1;
}

void calcCombination(int n, int i, u64 *ref)
{
	if (1 <= i && i <= n)
	{
		int self = getIndex(n, i);

		if (i == 1 || i == n)
			ref[self] = 1;
		else
		{
			int up_left = getIndex(n - 1, i - 1);
			int up_right = getIndex(n - 1, i);
			if (ref[up_left] == 0)
				calcCombination(n - 1, i - 1, ref);
			if (ref[up_right] == 0)
				calcCombination(n - 1, i, ref);

			ref[self] = ref[up_left] + ref[up_right];
		}
	}
}

inline u64 getCombination(int n, int i, u64 *ref)
{
	int t = getIndex(n, i);
	return ref[t];
}

int main(int argc, char **argv)
{
	int n, i;
	cin >> n >> i;

	calcCombination(n, i, triangleMatrix);

	u64 ans = getCombination(n, i, triangleMatrix);

	cout << ans;

	//system("pause");
	return 0;
}
