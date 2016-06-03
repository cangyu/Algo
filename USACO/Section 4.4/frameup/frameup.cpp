/*
ID: yhcy1991
PROG: frameup
LANG: C++11
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct rect
{
	bool exist;
	int x1, y1;//左上角的点
	int x2, y2;//右下角的点

	rect() :exist(false), x1(-1), y1(-1), x2(-1), y2(-1) {}
	void updateShape(int x, int y)
	{
		if (!exist)
			exist = true;

		x1 = x1 < 0 ? x : min(x1, x);
		y1 = y1 < 0 ? y : min(y1, y);
		x2 = x2 < 0 ? x : max(x2, x);
		y2 = y2 < 0 ? y : max(y2, y);
	}
};

int h, w;
rect r[26];

char map[32][32] = { 0 };
int adjList[26][1000] = { 0 };//有重复的元素，数组要开大
int linkCnt[26] = { 0 };
int indegree[26] = { 0 };
bool used[26] = { 0 };

int picCnt = 0;
vector<string> ans;

void topSort(int x, int level, string &cur);

int main(int argc, char** argv)
{
	freopen("frameup.in", "r", stdin);
	freopen("frameup.out", "w", stdout);

	//Input
	cin >> h >> w;
	getchar();
	for (int i = 0; i < h; i++)
	{
		cin.getline(map[i], w + 1, '\n');//getline是会强制写入'\0'的，所以第二个参数要加上1
		for (int j = 0; j < w; j++)
			if (map[i][j] != '.')
				r[map[i][j] - 'A'].updateShape(i, j);
	}

	//Build the graph based on adjacent list
	for (char t = 'A'; t <= 'Z'; t++)
	{
		int index = t - 'A';
		if (!r[index].exist)
			continue;

		for (int i = r[index].x1; i <= r[index].x2; i++)
		{
			for (int j = r[index].y1; j <= r[index].y2; j++)
			{
				if ((i == r[index].x1 || i == r[index].x2 || j == r[index].y1 || j == r[index].y2) && map[i][j] != t)
				{
					int coverIndex = map[i][j] - 'A';
					adjList[coverIndex][linkCnt[coverIndex]] = index;
					++linkCnt[coverIndex];
					++indegree[index];
				}
			}
		}
	}

	//Count the amount of pictures
	for (int i = 0; i < 26; i++)
		if (r[i].exist)
			++picCnt;


	//Topological sort
	string curAns = "";
	for (int i = 0; i < 26; i++)
		if (indegree[i] == 0 && r[i].exist && !used[i])
			topSort(i, picCnt, curAns);

	//Output
	for (size_t i = 0; i < ans.size(); i++)
		reverse(ans[i].begin(), ans[i].end());

	sort(ans.begin(), ans.end());
	
	for (auto t : ans)
		cout << t << endl;

	return 0;
}

void topSort(int x, int level, string &cur)
{
	if (level == 1)
	{
		cur.push_back('A' + x);
		ans.push_back(cur);
		cur.pop_back();
		return;
	}

	used[x] = true;
	cur.push_back('A' + x);
	for (int i = 0; i < linkCnt[x]; i++)
		indegree[adjList[x][i]]--;

	for (int i = 0; i < 26; i++)
		if (indegree[i] == 0 && r[i].exist && !used[i])
			topSort(i, level - 1, cur);

	for (int i = 0; i < linkCnt[x]; i++)
		indegree[adjList[x][i]]++;
	cur.pop_back();
	used[x] = false;
}
