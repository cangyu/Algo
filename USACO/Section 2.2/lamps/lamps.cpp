/*
ID: yhcy1991
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>

//some points to be noted:
//��6Ϊ����
//ÿ�������Ĵ����ǿ��Խ����ģ���ĳ������������2���൱��û��
//ÿ�������а��Ͳ���2��ѡ��4����������16����������Ǽ�������������unique��stateֻ��8�֣�����
//8��unique states��1, 3&4, 2, 4, 1&4, 3, 3&4�� ȫ���� ���������ƽ����С����
//��һ���Ż��ĵط���������ʱ�ͼ���Ƿ���ì�ܵ�״̬����6����ͬ��lampӦ������ͬ��״̬��

using namespace std;

int state[8][6] =
{
	{0,0,0,0,0,0},
	{0,0,1,1,1,0},
	{0,1,0,1,0,1},
	{0,1,1,0,1,1},
	{1,0,0,1,0,0},
	{1,0,1,0,1,0},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1}
};

int req[6];
int n, c;

bool check(int k);
void print(int len, int k);

int main(int argc, char **argv)
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	for (int i = 0; i < 6; i++)
		req[i] = -1;

	cin >> n >> c;
	int st;
	while (cin >> st && st != -1)
	{
		int index = (st - 1) % 6;
		if (req[index] == 0)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		else
			req[index] = 1;
	}
	while (cin >> st && st != -1)
	{
		int index = (st - 1) % 6;
		if (req[index] == 1)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		else
			req[index] = 0;
	}

	bool noMatch = true;
	switch (c)
	{
	case 0: 
		if (check(7)) { noMatch = false; print(n, 7); }
		break;
	case 1:
		if (check(0)) { noMatch = false; print(n, 0); }
		if (check(2)) { noMatch = false; print(n, 2); }
		if (check(3)) { noMatch = false; print(n, 3); }
		if (check(5)) { noMatch = false; print(n, 5); }
		break;
	case 2:
		if (check(1)) { noMatch = false; print(n, 1); }
		if (check(4)) { noMatch = false; print(n, 4); }
		if (check(6)) { noMatch = false; print(n, 8); }
		break;
	default:
		noMatch = true;
		for (int i = 0; i < 8; i++)
			if (check(i)) { noMatch = false; print(n, i); }
		break;
	}

	if (noMatch)
		cout << "IMPOSSIBLE" << endl;

	return 0;
}

bool check(int k)
{
	for (int i = 0; i < 6; i++)
	{
		if (req[i] != -1 && req[i] != state[k][i])
			return false;
	}
	return true;
}

void print(int len, int k)
{
	for (int i = 0; i < n; i++)
		cout << state[k][i % 6];
	cout << endl;
}
