/*
ID: yhcy1991
PROG: contact
LANG: C++
*/

#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

unsigned int f[13][4100];
char s[200005];

int a, b, n;
char c;
int len = 0;

int main(int argc, char **argv)
{
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);

	memset(f, sizeof(f), 0);
	memset(s, sizeof(s), 0);

	scanf("%d%d%d", &a, &b, &n);

	while ((c = getchar()) != EOF)
	{
		if (c == '0' || c == '1')
			s[len++] = c;
	}
	b = min(b, len);
	
	unsigned int val = 0;
	for (int i = 0; i < b; i++)
		val = val * 2 + s[i] - '0';
	f[b][val]++;
	unsigned int max_prev = val;

	for (int right = b; right < len; right++)
	{
		val = val << (32 - b + 1);
		val = val >> (32 - b);
		val += s[right] - '0';
		max_prev = max(max_prev, val);
		f[b][val]++;
	}

	for (int k = b - 1; k >= a; k--)
	{
		max_prev = 0;
		for (unsigned int i = 0; i <= max_prev; i++)
		{
			if (f[k + 1][i] == 0)
				continue;

			f[k][i >> 1] += f[k + 1][i];
			if (i != 0)
				f[k][(i << 1) >> 1] += f[k + 1][i];
			max_prev = max(max_prev, max(f[k][i >> 1], f[k][(i << 1) >> 1]));
		}
	}





	return 0;
}
