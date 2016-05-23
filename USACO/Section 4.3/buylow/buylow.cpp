/*
ID: yhcy1991
PROG: buylow
LANG: C++
*/

#include <iostream>
#include <ostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxLen = 108;

class HP//高精度的类，果然许多事情还是要靠自己，套别人的模板还是不如自己面向数据编程......
{
private:
	int len;
	int digit[maxLen];

public:
	HP() :len(1) { memset(digit, 0, sizeof(digit)); }
	HP(const HP &rhs) :len(rhs.len)
	{
		memset(digit, 0, sizeof(digit));
		memcpy(digit, rhs.digit, (len+1)*sizeof(int));
	}

	int getDigit(int n) const { return digit[n]; }
	void setDigit(int n, int t) { digit[n] = t; }
	int getLen() const { return len; }
	void setLen(int l) { len = l; }

	HP& operator=(int num)
	{
		len = 1;
		memset(digit, 0, sizeof(digit));
		
		while (num)
		{
			digit[len++] = num % 10;
			num /= 10;
		}
		len = max(1, len - 1);
		return *this;
	}

	HP& operator+=(const HP &rhs)
	{
		int i = 1, carry = 0;
		while (i <= rhs.len)
		{
			digit[i] += carry + rhs.digit[i];
			carry = digit[i] / 10;
			digit[i] %= 10;
			i++;
		}

		while (carry)
		{
			digit[i] += carry;
			carry = digit[i] / 10;
			digit[i] %= 10;
			i++;
		}

		len = max(i - 1, len);

		return *this;
	}
};

const int maxCnt = 5004;
int n = 0;
int a[maxCnt] = { 0 };
int f[maxCnt] = { 0 };
int post[maxCnt] = { 0 };
HP c[maxCnt];

ostream & operator<<(ostream &out, const HP &rhs);

int main(int argc, char** argv)
{
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] == a[i])
			{
				post[i] = j;
				break;
			}
		}
	}

	int fmax = -1;
	fill(f, f + sizeof(f) / sizeof(int), 1);
	for (int i = n; i >=1; i--)//DP找最长下降子序列，可以从前往后，也可以从后往前
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j])
				f[i] = max(f[i], 1 + f[j]);
		}
		fmax = max(fmax, f[i]);
	}

	for (int i = n; i >=1; i--)//关键在于如何避免重复，只取unique的部分！！！
	{
		if (post[i] == 0 && f[i] == 1)//仅在是最小single时才置为1
			c[i] = 1;
		else//将整个序列分成不重叠的片段，一段段地累计独立的序列，最后累加即可！
		{
			int last = post[i] != 0 ? post[i] - 1 : n;
			for (int j = i + 1; j <= last; j++)
			{
				if (a[i] > a[j] && f[j] == f[i] - 1)
					c[i] += c[j];
			}
		}
	}

	HP ans;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == fmax)
			ans += c[i];
	}

	cout << fmax << ' ' << ans << endl;
	return 0;
}

ostream & operator<<(ostream &out, const HP &rhs)
{
	for (int i = rhs.getLen(); i >= 1; i--)
		out << rhs.getDigit(i);
	return out;
}
