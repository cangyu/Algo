/*
ID: yhcy1991
PROG: heritage
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
	char ch;
	node *left, *right;
	node(char c='\0') :ch(c), left(NULL), right(NULL) {}
};

int n = 0;
char in[26], pre[26];
int in_rev[26], pre_rev[26];

node *reconstruct(int in_start, int in_end, int pre_start, int pre_end);
void post_show(node *root);

int main(int argc, char **argv) //Seems easy, actually fussing!!!
{
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);

	memset(in, 0, sizeof(in));
	memset(pre, 0, sizeof(pre));
	memset(in_rev, 0, sizeof(in_rev));
	memset(pre_rev, 0, sizeof(pre_rev));

	cin >> in >> pre;
	while (n < 26 && in[n] != '\0') n++;

	char c;
	for (int i = 0; i < n; i++)
	{
		c = in[i];
		in_rev[c - 'A'] = i;
		
		c = pre[i];
		pre_rev[c - 'A'] = i;
	}

	node *root = reconstruct(0, n - 1, 0, n - 1);

	post_show(root);
	cout << endl;

	return 0;
}

node *reconstruct(int in_start, int in_end, int pre_start, int pre_end)
{
	if (in_start > in_end || pre_start > pre_end)
		return NULL;

	node *cur = new node(pre[pre_start]);
	int k = in_rev[cur->ch - 'A'];

	bool leftEmpty = k - 1 < in_start;
	bool rightEmpty = k + 1 > in_end;

	if (leftEmpty || rightEmpty)
	{
		cur->left = reconstruct(in_start, k - 1, pre_start + 1, pre_end);
		cur->right = reconstruct(k + 1, in_end, pre_start + 1, pre_end);
	}
	else
	{
		int llen = k - in_start;//果然之前SB了，看长度就能确定最后一位了

		cur->left = reconstruct(in_start, k - 1, pre_start + 1, pre_start + llen);
		cur->right = reconstruct(k + 1, in_end, pre_start + llen + 1, pre_end);
	}

	return cur;
}

void post_show(node *root)
{
	if (!root)
		return;

	post_show(root->left);
	post_show(root->right);
	cout << root->ch;
}
