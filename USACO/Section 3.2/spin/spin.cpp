/*
ID: yhcy1991
PROG: spin
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

bitset<360> cur[6], tmp[6];
int speed[6] = { 0 };

int main(int argc, char **argv)
{
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);

	for (int i = 1; i <= 5; i++)
	{
		cur[i].reset();
		tmp[i].reset();
	}
	memset(speed, 0, sizeof(speed));

	for (int i = 1; i <= 5; i++)
	{
		cin >> speed[i];
		int w;
		cin >> w;
		for (int j = 0; j < w; j++)
		{
			int start, len;
			cin >> start >> len;
			for (int k = 0; k <= len; k++)
				cur[i].set((start + k) % 360);
		}
	}

	int t = 0;
	while (t < 360)
	{
		for (int deg = 0; deg < 360; deg++)
		{
			bool ok = true;
			for (int i = 1; i <= 5; i++)
			{
				if (!cur[i].test(deg))
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				cout << t << endl;
				return 0;
			}
		}

		for (int i = 1; i <= 5; i++)
		{
			for (int deg = 0; deg < 360; deg++)
				tmp[i][deg] = cur[i][(deg - speed[i] + 360) % 360];
			
			cur[i] = tmp[i];
		}

		t++;
	}

	cout << "none" << endl;

	return 0;
}
