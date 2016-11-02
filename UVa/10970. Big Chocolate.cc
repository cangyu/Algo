#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int m, n;
	while (cin >> m >> n)
		cout << m*n - 1 << endl;

	return 0;
}