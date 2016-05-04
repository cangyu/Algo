/*
ID: yhcy1991
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct node
{
	int p[8];
	int eigenValue;
	string ops;

	node(int src[], int k, const string &operation) :eigenValue(k), ops(operation) { memcpy(p, src, sizeof(p)); }
	node(const node &ref) :eigenValue(ref.eigenValue), ops(ref.ops) { memcpy(p, ref.p, sizeof(p)); }
};

int start[8] = { 0 };
int target[8] = { 0 };
bool hasGenerated[40320 + 4];

const int fac[9] = { 1,1,2,6,24,120,720,5040,40320 };
bool flag[8] = { false };

int cantor(int s[]);
node A_trans(const node &src);
node B_trans(const node &src);
node C_trans(const node &src);

int main(int argc, char **argv)
{
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);

	node (*trans[3])(const node &) = { A_trans,B_trans,C_trans };

	for (int i = 0; i < 8; i++)
	{
		start[i] = i + 1;
		cin >> target[i];
	}
	fill_n(hasGenerated, sizeof(hasGenerated) / sizeof(bool), false);

	queue<node> q;
	q.push(node(start, cantor(start), ""));
	hasGenerated[q.front().eigenValue] = true;

	const int finishValue = cantor(target);

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		if (cur.eigenValue == finishValue)
		{
			cout << cur.ops.length() << endl << cur.ops << endl;
			return 0;
		}

		for (int i = 0; i < 3; i++)
		{
			node t = trans[i](cur);
			if (!hasGenerated[t.eigenValue])
			{
				hasGenerated[t.eigenValue] = true;
				q.push(t);
			}
		}
	}

	return 0;
}

int cantor(int s[])
{
	int ans = 0;
	fill_n(flag, 8, false);
	for (int i = 0; i < 8-1; i++)
	{
		int cnt = s[i] - 1;
		for (int j = 1; j < s[i]; j++)
			if (flag[i])
				cnt--;

		ans += cnt*fac[7 - i];
		flag[s[i]] = true;
	}
	return ans + 1;
}

node A_trans(const node &src)
{
	int tmp[8];
	memcpy(tmp, src.p, sizeof(tmp));
	int i = 0, j = 7;
	while (i < j)
		swap(tmp[i++], tmp[j--]);

	return node(tmp, cantor(tmp), src.ops + 'A');
}

node B_trans(const node &src)
{
	int tmp[8];
	memcpy(tmp, src.p, sizeof(tmp));

	int k = tmp[0];
	tmp[0] = tmp[3];
	tmp[3] = tmp[2];
	tmp[2] = tmp[1];
	tmp[1] = k;

	k = tmp[7];
	tmp[7] = tmp[4];
	tmp[4] = tmp[5];
	tmp[5] = tmp[6];
	tmp[6] = k;

	return node(tmp, cantor(tmp), src.ops + 'B');
}

node C_trans(const node &src)
{
	int tmp[8];
	memcpy(tmp, src.p, sizeof(tmp));

	int k = tmp[1];
	tmp[1] = tmp[6];
	tmp[6] = tmp[5];
	tmp[5] = tmp[2];
	tmp[2] = k;

	return node(tmp, cantor(tmp), src.ops + 'C');
}