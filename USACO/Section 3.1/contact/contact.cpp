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

	/*��������*/
	while ((c = getchar()) != EOF)
	{
		if (c == '0' || c == '1')
			s[len++] = c;
	}
	b = min(b, len);//�������п���b�ϴ���ַ����϶�
	
	/*����ǰb��01�ַ�����ֵ*/
	u32 val = 0;
	for (int i = 0; i < b; i++)
		val = val * 2 + s[i] - '0';
	f[b][val]++;
	u32 max_prev = val;

	/*�ҵ����г���Ϊb�������Ӵ���ֵ����ͳ��Ƶ��*/
	for (int right = b; right < len; right++)
	{
		val = val << (32 - b + 1);
		val = val >> (32 - b);
		val += s[right] - '0';
		max_prev = max(max_prev, val);
		f[b][val]++;
	}
	maxVal[b] = max_prev;

	/*���ݳ���Ϊb���Ӵ�����Ƶ�Σ��Ƴ�����Ϊa��b-1���Ӵ���Ƶ�Σ�ͬʱ��¼ÿ���������Ӵ������ֵ�����ⲻ��Ҫ��scan*/
	for (int k = b - 1; k >= a; k--)
	{
		u32 max_cur = 0;
 		for (u32 i = 0; i <= max_prev; i++)
		{
			if (f[k + 1][i] == 0)
				continue;

			u32 t = i >> 1;//����ֻ��Ҫ����һ�Σ�����Ҫͷβ����һ�飬������ظ�������
			f[k][t] += f[k + 1][i];
			max_cur = max(max_cur, t);
		}
		
		/*����β������Ϊβ���Ĳ����Ķ����һ��Ƶ���޷�����һ���Ƴ�������*/
		u32 tail = 0;
		for (int j = len - k; j <len; j++)
			tail = tail * 2 + s[j] - '0';
		f[k][tail]++;

		max_prev = max_cur;
		maxVal[k] = max_prev;
	}

	/*������������sort*/
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

	/*���*/
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
			k++;//�����ʾ��Ҫ�����k������ע�⺬��
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

		if (k % 6 != 0)//���Ѿ����6k���������Ѿ������endl�ˣ��������ظ����endl
			cout << endl;

		freqCnt++;
	}

	return 0;
}

