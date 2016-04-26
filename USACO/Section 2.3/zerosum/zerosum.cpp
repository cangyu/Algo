/*
ID: yhcy1991
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int n;
char symbols[10];
char c[3] = { ' ','+','-' };

void dfs(int i, char t);
bool check();
void print();

int main(int argc, char **argv)
{
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < 3; i++)
		dfs(0, c[i]);

	return 0;
}

void dfs(int i, char t)
{
	symbols[i] = t;
	if (i + 1 >= n - 1)
	{
		if(check())//不能和上面连起来写，意义变了
			print();
	}
	else
	{
		for (int k = 0; k < 3; k++)
			dfs(i + 1, c[k]);
	}
}

bool check()
{
	int ans = 1;
	char prevOp;
	int right = 0;

	int i = 0;
	while (i < n - 1 && symbols[i] == ' ')
	{
		ans *= 10;
		ans += (i + 2);
		i++;
	}

	while (i < n - 1)
	{
		prevOp = symbols[i];
		right = i + 2;//update it immediately
		i++;
		while (i < n - 1 && symbols[i] == ' ')
		{
			right *= 10;
			right += (i + 2);
			i++;
		}
		switch (prevOp)
		{
		case '+':
			ans += right;
			break;
		case '-':
			ans -= right;
			break;
		default:
			break;
		}
	}
	return ans == 0;
}

void print()
{
	cout << 1;
	for (int i = 0; i < n - 1; i++)
		cout << symbols[i] << i + 2;
	cout << endl;
}

