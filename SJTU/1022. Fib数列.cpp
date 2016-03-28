//�þ���ĸ�ʽ����ʾ,�������
//����˷��㷨��֤��
//�ö��ַ������پ���ļ���,�����֣�һ���ǵݹ飬 ��һ���ǻ��ڶ��������ݵķǵݹ鷽��(����)
//�����Ĭ�ϳ�����32λ�ģ��Գ������д���32������λ���������⣬������ע���ڴ�����ʱ��������Ҫ��ǰ������1ת��Ϊu64

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
	const int xferMatrix[LEVEL][LEVEL] = { { 0, 1 }, { 1, 1 } }; //ת������
	int ans[LEVEL][LEVEL] = { { 1, 0 }, { 0, 1 } }; //��ʼ��Ϊ��λ����

	MatrixMultiply_WithMod(xferMatrix, MOD, n, ans);
	int ret = ans[1][0]; //��ֵΪ{1��0}={f(-1),f(0)},��ֵ����A^n���õ�{f(n-1),f(n)}

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


Reference���ǵݹ��㷨

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
