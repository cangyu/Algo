#include <iostream>

using namespace std;

inline int f(int n);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n)
		cout << f(n) << endl;

	return 0;
}

inline int f(int n)
{
	return n == 1 ? 1 : 1 + f(n / 2);
}
