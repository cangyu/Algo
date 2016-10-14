#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

const char *mahjong[] = {
	"1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
	"1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
	"1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
	"DONG", "NAN", "XI", "BEI",
	"ZHONG", "FA", "BAI"
};

char curCardsCnt[34] = { 0 };

int map2int(const string &_card);
bool check(void);
bool count(int remainCnt);
inline bool start_of_shunzi(int t);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	string card;
	int case_cnt = 0;
	while (cin >> card)
	{
		//Input
		if (card[0] == '0')
			break;
		
		++case_cnt;
		memset(curCardsCnt, 0, 34);

		++curCardsCnt[map2int(card)];
		for (int i = 1; i < 13; i++)
		{
			cin >> card;
			++curCardsCnt[map2int(card)];
		}

		//Solve
		bool ans[34] = { false };
		bool ok = false;
		for (int i = 0; i < 34; i++)
		{
			if (curCardsCnt[i] == 4)
				continue;

			++curCardsCnt[i];
			if (check())
			{
				ans[i] = true;
				if (!ok)
					ok = true;
			}
			--curCardsCnt[i];
		}

		//Output
		cout << "Case " << case_cnt << ':';
		if (!ok)
			cout << " Not ready";
		else
		{
			for (int i = 0; i < 34; i++)
				if (ans[i])
					cout << ' ' << mahjong[i];
		}
		cout << endl;
	}

	return 0;
}

int map2int(const string &_card)
{
	for (int i = 0; i < 34; i++)
		if (strcmp(mahjong[i], _card.c_str()) == 0)
			return i;

	return -1;
}

bool check(void)
{
	for (int i = 0; i < 34; i++)
		if (curCardsCnt[i] >= 2)
		{
			curCardsCnt[i] -= 2;
			bool curAns = count(4);
			curCardsCnt[i] += 2;
			if (curAns)
				return true;
		}

	return false;
}

bool count(int remainCnt)
{
	if (remainCnt == 0)
		return true;

	for (int i = 0; i < 34; i++)
	{
		if (curCardsCnt[i] == 0)
			continue;

		if (curCardsCnt[i] >= 3)
		{
			curCardsCnt[i] -= 3;
			bool curAns = count(remainCnt - 1);
			curCardsCnt[i] += 3;
			if (curAns)
				return true;
		}

		if (start_of_shunzi(i))
		{
			bool ok = true;
			for (int j = i; j < i + 3; j++)
			{
				if (curCardsCnt[j] == 0)
				{
					ok = false;
					break;
				}
			}

			if (ok)
			{
				for (int j = i; j < i + 3; j++)
					--curCardsCnt[j];
				bool curAns = count(remainCnt - 1);
				for (int j = i; j < i + 3; j++)
					++curCardsCnt[j];
				if (curAns)
					return true;
			}
		}
	}

	return false;
}

inline bool start_of_shunzi(int t)
{
	return (t >= 0 && t <= 6) || (t >= 9 && t <= 15) || (t >= 18 && t <= 24);
}
