#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n = 0, case_cnt = 0;
	while (cin >> n && n>0)
		cout << "Case " << ++case_cnt << ": " << ceil(log2(n)) << endl;

	return 0;
}