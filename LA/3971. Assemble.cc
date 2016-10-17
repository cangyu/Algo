#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Item
{
	int price;
	int quality;

	Item(int _p, int _q) :price(_p), quality(_q) {}
};

int getDesignator(const string &_name);
bool check(int _q);

const int N = 1000 + 5;

int type_cnt = 0;
map<string, int> designation;
vector<Item> comp[N];
int n = 0, b = 0;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int T = 0;
	cin >> T;

	while(T--)
	{
		cin >> n >> b;

		//Init
		type_cnt = 0;
		designation.clear();
		for (int i = 0; i < N; i++)
			comp[i].clear();

		//Input
		int q_max = 0, q_min = 2147483647;
		for (int i = 0; i < n; i++)
		{
			string type, name;
			int p, q;
			cin >> type >> name >> p >> q;
			comp[getDesignator(type)].push_back(Item(p, q));
			if (q > q_max)
				q_max = q;
			if (q < q_min)
				q_min = q;
		}
		
		//Binary Check
		--q_min;
		while (q_min < q_max)
		{
			int q = q_min + (q_max - q_min + 1) / 2;//通过加1保证前进
			if (check(q))
				q_min = q;
			else
				q_max = q - 1;
		}
		cout << q_min << endl;
	}

	return 0;
}

int getDesignator(const string &_name)
{
	auto it = designation.find(_name);
	if (it == designation.end())
	{
		designation[_name] = type_cnt;
		return type_cnt++;
	}
	else
		return it->second;
}

bool check(int _q)
{
	int cost = 0;
	for (auto it = designation.begin(); it != designation.end(); ++it)
	{
		const int id = it->second;
		int cheapest = b + 1;
		bool exist = false;

		for (int i = 0; i < comp[id].size(); i++)//会把int转成unsigned
		{
			if (comp[id][i].quality >= _q)//找满足quality要求的最便宜的
			{
				if (!exist)
					exist = true;

				if (comp[id][i].price < cheapest)
					cheapest = comp[id][i].price;
			}
		}

		if (!exist)
			return false;

		cost += cheapest;
		if (cost > b)
			return false;
	}

	return true;
}
