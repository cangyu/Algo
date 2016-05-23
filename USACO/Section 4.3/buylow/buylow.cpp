

#include <iostream>
#include <ostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxlen = 20;

class hpNum
{
public:
	int len;
	int s[maxlen];

	hpNum() :len(1){ memset(s, 0, sizeof(s)); }
	hpNum(int inte)
	{
		memset(s, 0, sizeof(s));
		*this = inte; 
	}
	hpNum(const char *str)
	{
		memset(s, 0, sizeof(s));
		*this = str; 
	}
	hpNum(const hpNum &rhs) :len(rhs.len)
	{
		memset(s, 0, sizeof(s));
		memcpy(s, rhs.s, sizeof(s));
	}

	friend ostream & operator<<(ostream& out, const hpNum &x);
	
	hpNum operator=(int inte);
	hpNum operator=(const char *str);
	hpNum operator+(const hpNum &rhs);
	hpNum operator-(const hpNum &rhs);
	hpNum operator*(const hpNum &rhs);
	hpNum operator/(const hpNum &rhs);
	hpNum operator%(const hpNum &rhs);

	int cmp(const hpNum &rhs);
};

ostream & operator<<(ostream &out, const hpNum  &x)
{
	for (int i = x.len; i >= 1; i--)
		out << x.s[i];
	return out;
}

hpNum hpNum::operator=(int inte)
{
	if (inte == 0)
	{
		len = 1;
		s[1] = 0;
		return *this;
	}

	len = 0;
	while (inte > 0)
	{
		s[++len] = inte % 10;
		inte /= 10;
	}
	return *this;
}

hpNum hpNum::operator=(const char *str)
{
	len = strlen(str);
	for (int i = 1; i <= len; i++)
		s[i] = str[len - i] - '0';
	return *this;
}

hpNum hpNum::operator+(const hpNum &rhs)
{
	int i = 1;
	hpNum c;

	while (i <= len || i <= rhs.len || c.s[i])
	{
		if (i <= len)
			c.s[i] += s[i];
		if (i <= len)
			c.s[i] += rhs.s[i];

		c.s[i + 1] = c.s[i] / 10;
		c.s[i] %= 10;

		i++;
	}
	
	c.len = max(1, i - 1);
	return c;
}

hpNum hpNum::operator-(const hpNum &rhs)
{
	int i, j;
	hpNum c;

	for (i = 1, j = 0; i <= len; i++)// no handling of negative results?
	{
		c.s[i] = s[i] - j;
		if (i <= rhs.len)
			c.s[i] -= rhs.s[i];
		if (c.s[i] < 0)
		{
			j = 1;
			c.s[i] += 10;
		}
		else
			j = 0;
	}

	c.len = len;
	while (c, len > 1 && c.s[c, len] == 0)
		c.len--;

	return c;
}

hpNum hpNum::operator*(const hpNum &rhs)
{
	int i, j;
	hpNum c;

	c.len = len + rhs.len;

	for (i = 1; i <= c.len; i++)
		c.s[i] = 0;

	for ( i = 1; i <= len; i++)
		for (j = 1; j <= rhs.len; j++)
			c.s[i + j - 1] += s[i] * rhs.s[j];

	for (i = 1; i < c.len; i++)
	{
		c.s[i + 1] += c.s[i] / 10;
		c.s[i] %= 10;
	}

	while (c.s[i])
	{
		c.s[i + 1] = c.s[i] / 10;
		c.s[i] %= 10;
		i++;
	}

	while (i > 1 && c.s[i] == 0)
		i--;

	c.len = i;
	return c;
}

hpNum hpNum::operator/(const hpNum &rhs)
{
	int i, j;
	hpNum c, d(0);

	for (i = len; i > 0; i--)
	{
		if (!(d.len == 1 && d.s[1] == 0))
		{
			for (j = d.len; j > 0; j--)
				d.s[j + 1] = d.s[j];
			++d.len;
		}
		d.s[1] = s[i];
		c.s[i] = 0;
		while ((j = d.cmp(rhs)) >= 0)
		{
			d = d - rhs;
			c.s[i]++;
			if (j == 0)
				break;
		}
	}
	c.len = len;
	while ((c.len > 1 && c.s[c.len] == 0))
		c.len--;

	return c;
}

hpNum hpNum::operator%(const hpNum &rhs)
{
	int i, j;
	hpNum d(0);
	for (i = len; i > 0; i--)
	{
		if (!(d.len == 1 && d.s[1] == 0))
		{
			for (j = d.len; j > 0; j--)
				d.s[j + 1] = d.s[j];
			++d.len;
		}
		d.s[1] = s[i];
		while ((j = d.cmp(rhs)) >= 0)
		{
			d = d - rhs;
			if (j == 0)
				break;
		}
	}

	return d;
}

int hpNum::cmp(const hpNum &rhs)
{
	if (len != rhs.len)
		return len > rhs.len ? 1 : -1;

	int i = len;
	while (i > 1 && s[i] == rhs.s[i])
		i--;
	return s[i] - rhs.s[i];
}

int n;
int a[5004] = { 0 };
int post[5004] = { 0 };
int f[5004] = { 0 };
hpNum c[5004];

using namespace std;

int main(int argc, char **argv) 
{
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);

	for (int i = 1; i <= n - 1; i++)
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

	fill_n(f, sizeof(f) / sizeof(int), 1);

	for (int i = n - 1; i >= 1; i--)
	{
		for (int k = i + 1; k <= n; k++)
		{
			if (a[i] > a[k])
				f[i] = max(f[i], 1 + f[k]);
		}
	}

	int maxIndex = 0, fmax = -1;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] > fmax)
		{
			fmax = f[i];
			maxIndex = i;
		}
	}

	for (int i = n ; i >= 1; i--)
	{
		if (post[i] == 0 && f[i] == 1)
			c[i] = 1;
		else
		{
			const int last = post[i] != 0 ? post[i] - 1 : n;

			for (int j = i + 1; j <= last; j++)
			{
				if (a[i] > a[j] && f[j] == f[i] - 1)
					c[i] = c[i] + c[j];
			}

			/*
			if (c[i].len == 2 && c[i].s[2] == 0)
				cerr << "unusual!" << endl;
			*/
		}
	}
	
	hpNum ans(0);
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == fmax)
			ans = ans + c[i];
	}
	
	cout << fmax << ' ' << ans << endl;
	return 0;
}
