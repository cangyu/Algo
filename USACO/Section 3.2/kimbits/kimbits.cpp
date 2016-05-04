/*
ID: yhcy1991
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned int u32;

u32 N, L, I;

inline int cntOnes(u32 t);
void print(u32 x, int len);

int main(int argc, char **argv)
{
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);

	cin >> N >> L >> I;

	u32 cnt = 0;
	int w=-1;
	while (cnt < I && w <= 2147483647)
	{
		w++;
		if (cntOnes(w) <= L)
			cnt++;
	}
	
	print(w, N);
	return 0;
}

inline int cntOnes(u32 t)
{
	u32 num = t;
	num = (num & 0x55555555) + ((num & 0xAAAAAAAA) >> 1);
	num = (num & 0x33333333) + ((num & 0xCCCCCCCC) >> 2);
	num = (num & 0x0F0F0F0F) + ((num & 0xF0F0F0F0) >> 4);
	num = (num & 0x00FF00FF) + ((num & 0xFF00FF00) >> 8);
	num = (num & 0x0000FFFF) + ((num & 0xFFFF0000) >> 16);
	return num;
}

void print(u32 x,int len)
{
	string ans;

	while (x)
	{
		ans += (x % 2 + '0');
		x /= 2;
	}
	ans.append(32 - ans.length(), '0');
	reverse(ans.begin(), ans.end());
	ans = ans.substr(32 - len, len);
	cout << ans << endl;
}
