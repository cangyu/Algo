//已经去掉的在后面即使再出现也没事

#include <iostream>
#include <cmath>

using namespace std;

int process(int n);

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	cout << N << "=";
	process(N);
	return 0;
}

int process(int n)
{
	int curPrime = 2;
	int curPrimeCnt = 0;

	const int up_limit = sqrt(n);

	while (n != 1)
	{
		while (n%curPrime == 0)
		{
			curPrimeCnt++;
			n /= curPrime;
		}
		if (curPrimeCnt != 0)
		{
			cout << curPrime << "(" << curPrimeCnt << ")";
			curPrimeCnt = 0;
		}
		curPrime++;

		if (curPrime>up_limit)
			curPrime = n;
	}
	return 0;
}
