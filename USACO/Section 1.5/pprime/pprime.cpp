/*
ID: yhcy1991
PROG: pprime
LANG: C++
*/

//从一半入手，枚举之，从而避免n层for循环
//尽可能优化，但要避免过度复杂化
//慎用operator +=

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x%i == 0)
			return false;
	return true;
}

int getNumLen(int x)
{
	int cnt = 0;
	while (x)
	{
		x /= 10;
		cnt++;
	}
	return cnt;
}

int getReverseNum(int x)
{
	int tmp[10] = { 0 };
	int k = 0;
	while (x)
	{
		tmp[k++] = x % 10;
		x /= 10;
	}
	int res = 0, cnt = 0;
	while (cnt < k)
	{
		res *= 10;
		res += tmp[cnt++];
	}
	return res;
}

int main()
{
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	int a, b;
	fin >> a >> b;
	int la = getNumLen(a), lb = getNumLen(b);

	if (la == 1)
	{
		for (int i = a; i < 10; i++)
			if (isPrime(i))
				fout << i << endl;
	}
	if (la == 1)
		la++;

	for (int i = la; i <= lb; i++)
	{
		int len = i / 2;
		int start = pow(10, len - 1);
		int end = pow(10, len) - 1;
		for (int j = start; j <= end; j++)
		{
			if ((j / start) % 2 == 0)
			{
				j += start - 1;
				continue;
			}
			int rev = getReverseNum(j);
			if (i % 2 == 0)
			{
				int p = j*pow(10, len) + rev;
				if (a <= p && p <= b && isPrime(p))
					fout << p << endl;
			}
			else
			{
				int cur = j*pow(10, len + 1) + rev;
				for (int w = 0; w < 10; w++)
				{
					int p = cur + w*pow(10, len); //be careful to use operator += !!!
					if (a <= p && p <= b && isPrime(p))
						fout << p << endl;
				}
			}
		}
	}

	fin.close();
	fout.close();
	return 0;
}