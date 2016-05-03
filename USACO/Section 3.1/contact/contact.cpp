/*
ID: yhcy1991
PROG: contact
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned int u32;

struct node
{
	int freq;
	int len;
	int val;

	void print() const
	{
		string res;
		int x = val;
		while (x)
		{
			res += ('0' + x % 2);
			x /= 2;
		}
		res.append(len - res.length(), '0');
		reverse(res.begin(), res.end());
		cout << res;
	}
};

u32 f[13][4100];
char s[200005];
int maxVal[13] = { 0 };
node q[12 * 4096];

int a, b, n;
char c;
int len = 0;

bool my_cmp(const node &lhs, const node &rhs)
{
	if (lhs.freq != rhs.freq)
		return lhs.freq > rhs.freq;
	else if (lhs.len != rhs.len)
		return lhs.len < rhs.len;
	else
		return lhs.val < rhs.val;
}

int main(int argc, char **argv)
{
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);

	memset(f, sizeof(f), 0);
	memset(s, sizeof(s), 0);

	scanf("%d%d%d", &a, &b, &n);

	/*输入数据*/
	while ((c = getchar()) != EOF)
	{
		if (c == '0' || c == '1')
			s[len++] = c;
	}
	b = min(b, len);//理论上有可能b较大而字符串较短
	
	/*计算前b个01字符串的值*/
	u32 val = 0;
	for (int i = 0; i < b; i++)
		val = val * 2 + s[i] - '0';
	f[b][val]++;
	u32 max_prev = val;

	/*找到所有长度为b的连续子串的值，并统计频次*/
	for (int right = b; right < len; right++)
	{
		val = val << (32 - b + 1);
		val = val >> (32 - b);
		val += s[right] - '0';
		max_prev = max(max_prev, val);
		f[b][val]++;
	}
	maxVal[b] = max_prev;

	/*根据长度为b的子串及其频次，推出长度为a到b-1的子串的频次，同时记录每个长度下子串的最大值来避免不必要的scan*/
	for (int k = b - 1; k >= a; k--)
	{
		u32 max_cur = 0;
 		for (u32 i = 0; i <= max_prev; i++)
		{
			if (f[k + 1][i] == 0)
				continue;

			u32 t = i >> 1;//这里只需要计算一次，不需要头尾都掐一遍，否则会重复！！！
			f[k][t] += f[k + 1][i];
			max_cur = max(max_cur, t);
		}
		
		/*处理尾串，因为尾串的产生的多余的一个频次无法从上一层推出！！！*/
		u32 tail = 0;
		for (int j = len - k; j <len; j++)
			tail = tail * 2 + s[j] - '0';
		f[k][tail]++;

		max_prev = max_cur;
		maxVal[k] = max_prev;
	}

	/*整理结果，借助sort*/
	int cnt = 0;
	for (int i = a; i <= b; i++)
	{
		for (int j = 0; j <= maxVal[i]; j++)
		{
			if (f[i][j] != 0)
			{
				q[cnt].freq = f[i][j];
				q[cnt].len = i;
				q[cnt].val = j;
				cnt++;
			}
		}
	}

	sort(q, q + cnt, my_cmp);

	/*输出*/
	int outIndex = 0;
	int freqCnt = 0;
	while (outIndex < cnt)
	{
		if (freqCnt >= n)
			break;

		int cur_freq = q[outIndex].freq;
		cout << cur_freq << endl;
		int k = 0;
		while (q[outIndex].freq == cur_freq)
		{
			k++;//这里表示将要输出第k个数，注意含义
			if (k % 6 == 1)
				q[outIndex].print();
			else
			{
				cout << " ";
				q[outIndex].print();
			}

			if (k % 6 == 0)
				cout << endl;

			outIndex++;
		}

		if (k % 6 != 0)//若已经输出6k个数，则已经输出过endl了，不用再重复输出endl
			cout << endl;

		freqCnt++;
	}

	return 0;
}

