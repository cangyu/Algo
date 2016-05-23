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

class HP//�߾��ȵ��࣬��Ȼ������黹��Ҫ���Լ����ױ��˵�ģ�廹�ǲ����Լ��������ݱ��......
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
	for (int i = n; i >=1; i--)//DP����½������У����Դ�ǰ����Ҳ���ԴӺ���ǰ
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j])
				f[i] = max(f[i], 1 + f[j]);
		}
		fmax = max(fmax, f[i]);
	}

	for (int i = n; i >=1; i--)//�ؼ�������α����ظ���ֻȡunique�Ĳ��֣�����
	{
		if (post[i] == 0 && f[i] == 1)//��������Сsingleʱ����Ϊ1
			c[i] = 1;
		else//���������зֳɲ��ص���Ƭ�Σ�һ�ζε��ۼƶ��������У�����ۼӼ��ɣ�
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
