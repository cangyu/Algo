/*
ID: yhcy1991
PROG: shuttle
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char** argv)//找规律。。。面向输出编程。。。
{
	freopen("shuttle.in", "r", stdin);
	freopen("shuttle.out", "w", stdout);

	int total = 0;//格式控制
	int n, start;
	cin >> n;
	start = n + 1;

	for (int i = 2; i <= n + 1; i++)
	{
		if (i % 2 == 0)
		{
			start--;
			for (int k = 0; k < i; k++)
			{
				cout << start;

				total++;
				if (total%20 == 0)
					cout << endl;
				else
					cout << " ";

				if (k!=i-1)
					start += 2;
			}
		}
		else
		{
			start++;
			for (int k = 0; k < i; k++)
			{
				cout << start;

				total++;
				if (total % 20 == 0)
					cout << endl;
				else
					cout << " ";

				if (k != i - 1)
					start -= 2;
			}
		}
	}

	for (int i = n; i >= 2; i--)
	{
		if (i % 2 == 0)
		{
			start++;
			for (int k = 0; k < i; k++)
			{
				cout << start;

				total++;
				if (total % 20 == 0)
					cout << endl;
				else
					cout << " ";

				if (k != i - 1)
					start += 2;
			}
		}
		else
		{
			start--;
			for (int k = 0; k < i; k++)
			{
				cout << start;

				total++;
				if (total % 20 == 0)
					cout << endl;
				else
					cout << " ";

				if (k != i - 1)
					start -= 2;
			}
		}
	}

	cout << n + 1 << endl;

	return 0;
}

