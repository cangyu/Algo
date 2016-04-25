/*
ID: yhcy1991
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

typedef struct primitive
{
	char c[15];
	int len;
}PrimitiveTypeDef, *pPrimitiveTypeDef;

PrimitiveTypeDef p[225];
char s[200250];
int f[200250];

int pCnt, sLen;

int solve();

int main(int argc, char **argv)
{
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	//freopen("prefix.err", "w", stderr);

	cout << solve() << endl;

	return 0;
}

int solve()
{
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	pCnt = sLen = 0;
	while (cin >> p[pCnt].c && *(p[pCnt].c) != '.')
	{
		p[pCnt].len = strlen(p[pCnt].c);
		pCnt++;//不能将这里的++写到上面的其中一个pCnt中，不同的编译器会采用不同的行为！！！
	}

	/*
	cerr << "pCnt=" << pCnt << endl;
	for (int i = 0; i < pCnt; i++)
		cerr << "NO. " << i << " primitive is: " << p[i].c << " , and the length is: " << p[i].len << endl;
	*/

	char tmp[80];
	while (cin >> tmp)
	{
		int curLen = strlen(tmp);
		memcpy(s + sLen, tmp, curLen);
		sLen += curLen;
	}

	/*
	cerr << "sLen=" << sLen << endl;
	cerr << s << endl;
	*/

	for (int i = sLen - 1; i >= 0; i--)
	{
		for (int j = 0; j < pCnt; j++)
		{
			if (i - 1 + p[j].len >= sLen || strncmp(s + i, p[j].c, p[j].len) != 0)
				continue;
			else
				f[i] = max(f[i], f[i + p[j].len] + p[j].len);
		}
	}

	return f[0];
}