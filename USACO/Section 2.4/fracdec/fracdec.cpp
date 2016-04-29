/*
ID: yhcy1991
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool hasExamined[100005];
int place[100005];
int res[100005];
int cnt = 0;

int main(int argc, char **argv)//就是模拟，通过重复的余数确定循环节
{
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);

	fill_n(hasExamined, sizeof(hasExamined) / sizeof(bool), false);
	memset(place, 0, sizeof(place));
	memset(res, 0, sizeof(res));

	stringstream ss;
	int a, b;
	cin >> a >> b;
	ss << a / b << '.';
	a %= b;
	if (a == 0)
	{
		ss << 0;
		cout << ss.str() << endl;
		return 0;
	}

	while (a && !hasExamined[a])
	{
		hasExamined[a] = true;
		place[a] = cnt;
		cnt++;
		a *= 10;
		res[cnt] = a / b;
		a %= b;
	}

	if (a == 0)
	{
		for (int i = 1; i <= cnt; i++)
			ss << res[i];
	}
	else
	{
		int end = cnt;
		int start = place[a] + 1;
		for (int i = 1; i < start; i++)
			ss << res[i];
		ss << '(';
		for (int i = start; i <= end; i++)
			ss << res[i];
		ss << ')';
	}

	string ans = ss.str();

	for (int i = 1; i <= ans.length(); i++)
	{
		cout << ans[i - 1];
		if (i % 76 == 0)
			cout << endl;
	}
	if (ans.length() % 76 != 0)
		cout << endl;

	return 0;
}
