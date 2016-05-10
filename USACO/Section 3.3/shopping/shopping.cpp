/*
ID: yhcy1991
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct discount
{
	int num;
	int total_price;
	int amount[1000];
	discount() :num(0), total_price(0) { memset(amount, 0, sizeof(amount)); }
};

struct item
{
	int code;
	int amount;
	int price;
	item() :code(0), amount(0), price(0) {}
};

discount offer[100];
item buy[6];

int res[6][6][6][6][6];
int s = 0, b = 0;

int dfs(int b1, int b2, int b3, int b4, int b5);
bool check(int offer_index, int target_amount[], int remain[]);

int main(int argc, char **argv)
{
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);

	memset(res, 0, sizeof(res));
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		cin >> offer[i].num;
		for (int j = 0; j < offer[i].num; j++)
		{
			int code, k;
			cin >> code >> k;
			*(offer[i].amount + code) = k;
		}
		cin >> offer[i].total_price;
	}
	cin >> b;
	for (int i = 1; i <= b; i++)
		cin >> buy[i].code >> buy[i].amount >> buy[i].price;

	cout << dfs(buy[1].amount, buy[2].amount, buy[3].amount, buy[4].amount, buy[5].amount) << endl;

	return 0;
}

int dfs(int b1, int b2, int b3, int b4, int b5)
{
	if (res[b1][b2][b3][b4][b5] != 0)
		return res[b1][b2][b3][b4][b5];

	int a[6] = { 0,b1,b2,b3,b4,b5 };

	int ans = 0;
	for (int i = 1; i <= 5; i++)
		ans += a[i] * buy[i].price;

	for (int i = 0; i < s; i++)
	{
		int remain[6] = { 0 };
		if (check(i, a, remain))
		{
			int tmp = offer[i].total_price;

			if (tmp < ans)
				tmp += dfs(remain[1], remain[2], remain[3], remain[4], remain[5]);

			ans = min(ans, tmp);
		}
	}

	return res[b1][b2][b3][b4][b5] = ans;
}

bool check(int offer_index, int target_amount[], int remain[])
{
	int cnt = 0;
	for (int i = 1; i <= 5; i++)
	{
		if (target_amount[i] != 0)
			cnt++;
	}

	if (offer[offer_index].num > cnt)
		return false;

	memcpy(remain, target_amount, 6*sizeof(int));

	for (int i = 1; i <= 5; i++)
	{
		int c = buy[i].code;
		if (*(offer[offer_index].amount + c) > target_amount[i])
			return false;
		else
			remain[i] -= *(offer[offer_index].amount + c);
	}

	return true;
}
