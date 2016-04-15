// I think the idea is right,but got one WA

#include<iostream>

using namespace std;

char board[3][3];

bool canWin(char c);
bool check(int p, int q, char c, bool & rf);

int main(int argc, char **argv)
{
	//freopen("1512.in", "r", stdin);
	//freopen("1512.out", "w", stdout);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];

	bool rf;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'b')
			{
				if (check(i, j, 'x', rf))
				{
					cout << i + 1 << ' ' << j + 1 << endl;
					return 0;
				}
			}
		}
	}

	cout << "jerk" << endl;

	return(0);
}

bool check(int p, int q, char c, bool & rf)
{
	int rev = 'x' + 'o' - c;
	board[p][q] = c;
	bool f, res = false;

	if (f = canWin(c))
	{
		board[p][q] = 'b';
		return true;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'b')
			{
				if (rf = check(i, j, rev, f))
				{
					board[p][q] = 'b';
					return false;
				}
				else
					res |= f;
			}
		}
	}

	board[p][q] = 'b';
	return res;
}

bool canWin(char c)
{
	for (int i = 0; i < 3; i++)
		if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
			return true;

	for (int j = 0; j < 3; j++)
		if (board[0][j] == c && board[1][j] == c && board[2][j] == c)
			return true;

	if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
		return true;

	if (board[0][2] == c&&board[1][1] == c && board[2][0] == c)
		return true;

	return false;
}
