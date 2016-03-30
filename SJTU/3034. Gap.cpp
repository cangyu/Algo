//试除法，从n向两边找
//Is there any better way? Now the time complexity is O(n^2)
//用费马小定理？

#include<iostream>
#include<cmath>

using namespace std;

int calcGapBetween(int n);
bool isPrime(int n);

int main(int argc, char **argv)
{
	int n;
	cin >> n;

	int gap = calcGapBetween(n);

	cout << gap << endl;

	//system("pause");
	return 0;
}

int calcGapBetween(int n)
{
	if (isPrime(n))
		return 0;

	int left = n - 1, right = n + 1;
	while (!isPrime(left))
		left--;
	while (!isPrime(right))
		right++;
	return right - left;
}

bool isPrime(int n)
{
	if (n <= 2)
		return true;
	if (n % 2 == 0)
		return false;

	int ceiling = sqrt(n);
	for (int j = 3; j <= ceiling; j += 2)
	{
		if (n%j == 0)
			return false;
	}
	return true;
}
