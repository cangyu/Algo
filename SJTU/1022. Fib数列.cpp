//用矩阵的格式来表示,简洁明了
//带余乘方算法的证明
//用二分法来加速矩阵的计算,有两种，一种是递归， 另一种是基于二进制求幂的非递归方法(本例)
//计算机默认常量是32位的，对常量进行大于32的左移位运算会出问题，若不加注意在大数的时候会出错，需要提前将常量1转化为u64

#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long u64;

const int MOD = 2010;
const int LEVEL = 2;

int MatrixMultiply_WithMod(const int ref[][LEVEL], int mod, u64 times, int res[][LEVEL]);

int main(int argc, char ** argv)
{
	u64 n;
	cin >> n;
	const int xferMatrix[LEVEL][LEVEL] = { { 0, 1 }, { 1, 1 } }; //转换矩阵
	int ans[LEVEL][LEVEL] = { { 1, 0 }, { 0, 1 } }; //初始化为单位矩阵

	MatrixMultiply_WithMod(xferMatrix, MOD, n, ans);
	int ret = ans[1][0]; //初值为{1，0}={f(-1),f(0)},初值乘以A^n即得到{f(n-1),f(n)}

	cout << ret;
	//system("pause");
	return 0;
}

int MatrixMultiply_WithMod(const int ref[][LEVEL], int mod, u64 times, int res[][LEVEL])
{
	int refGalary[64][LEVEL][LEVEL] = { 0 };
	int maxIndex = log2l(times);// Attention should also be paid here.

	//Initialization
	for (int i = 0; i < LEVEL; i++)
		for (int j = 0; j < LEVEL; j++)
			refGalary[0][i][j] = ref[i][j] % mod;

	//Calculation
	for (int l = 1; l <= maxIndex; l++)
	{
		for (int i = 0; i < LEVEL; i++)
			for (int j = 0; j < LEVEL; j++)
			{
				for (int k = 0; k < LEVEL; k++)
					refGalary[l][i][j] += (refGalary[l - 1][i][k] * refGalary[l - 1][k][j]) % mod;

				refGalary[l][i][j] %= mod;
			}
	}

	//Resulting
	for (int l = 0; l <= maxIndex; l++)
	{
		u64 test = (((u64)1) << l);//Important to convert the constant 1 to 64-bit format in advance!
		if (times&test)
		{
			int tmp[LEVEL][LEVEL] = { 0 };
			for (int i = 0; i < LEVEL; i++)
			{
				for (int j = 0; j < LEVEL; j++)
				{
					for (int k = 0; k < LEVEL; k++)
						tmp[i][j] += (refGalary[l][i][k] * res[k][j]) % mod;

					tmp[i][j] %= mod;
				}
			}
			for (int i = 0; i < LEVEL; i++)
				for (int j = 0; j < LEVEL; j++)
					res[i][j] = tmp[i][j];
		}
	}

	return 0;
}

/*
Reference：递归算法

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <map>

using namespace std;

map <long long int, int > FF;

int F(long long int n)
{
	if (n == 0) return 0;
	if (n < 3) return 1;
	if (FF.find(n) != FF.end())
		return FF[n];
	long long int n1 = n / 2, n2 = n - n1;
	if (n1 == n2)
	{
		int Fn1 = F(n1);
		int res = ((2 * F(n1 - 1) + Fn1)*Fn1) % 2010;
		FF[n] = res;
		return res;
	}
	int Fn1 = F(n1), Fn2 = F(n2);
	int res = (Fn1 *Fn1 + Fn2*Fn2) % 2010;
	FF[n] = res;
	return res;
}

int main()
{
	long long int N;
	scanf("%lld", &N);
	printf("%d\n", F(N));
	//system("pause");
	return 0;
}
*/
