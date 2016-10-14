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

using namespace std;

const int N = 4;
int view[24][7], color[N][7], pose[N][7];
int n = 0;

void init_view(void);
void rot_up(int a[], int n);
void rot_right(int a[], int n);
int check(int cur);
int count(void);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	init_view();//生成24种可能的姿态

	while (cin>>n && n != 0)
	{
		int color_cnt = 0;
		map<string, int> c;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < 7; j++)
			{
				string cur_color;
				cin >> cur_color;
				if (c.find(cur_color) == c.end())
				{
					c[cur_color] = color_cnt;
					color[i][j] = color_cnt;
					++color_cnt;
				}
				else
					color[i][j] = c[cur_color];
			}
		}

		cout << check(0) << endl;//dfs,逐个枚举，注意终止条件
	}

	return 0;
}

void init_view(void)
{
	//初始全部为基准态
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 7; j++)
			view[i][j] = j;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 7; j++)
			pose[i][j] = j;

	int cnt = 0;

	//1在顶面
	for (int i = 0; i < 4; i++)
	{
		rot_up(view[cnt], 1);
		rot_right(view[cnt++], i);
	}

	//2在顶面
	for (int i = 0; i < 4; i++)
	{
		rot_right(view[cnt], 3);
		rot_up(view[cnt], 1);
		rot_right(view[cnt++], i);
	}

	//3在顶面
	for (int i = 0; i < 4; i++)
		rot_right(view[cnt++], i);

	//4在顶面
	for (int i = 0; i < 4; i++)
	{
		rot_up(view[cnt], 2);
		rot_right(view[cnt++], i);
	}

	//5在顶面
	for (int i = 0; i < 4; i++)
	{
		rot_right(view[cnt], 1);
		rot_up(view[cnt], 3);
		rot_right(view[cnt++], i);
	}

	//6在顶面
	for (int i = 0; i < 4; i++)
	{
		rot_up(view[cnt], 3);
		rot_right(view[cnt++], i);
	}
}

void rot_up(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int tmp = a[1];
		a[1] = a[4];
		a[4] = a[6];
		a[6] = a[3];
		a[3] = tmp;
	}
}

void rot_right(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int tmp = a[2];
		a[2] = a[1];
		a[1] = a[5];
		a[5] = a[6];
		a[6] = tmp;
	}
}

int check(int cur)
{
	if (cur == n)
		return count();

	int ret = -1;
	for (int i = 0; i < 24; i++)
	{
		memcpy(pose[cur], view[i], sizeof(pose[cur]));
		int curAns = check(cur + 1);

		if (ret == -1)
			ret = curAns;
		else if (curAns < ret)
			ret = curAns;
	}

	return ret;
}

int count(void)
{
	int change_cnt = 0;

	for (int face = 1; face <= 6; ++face)
	{
		//找到给定视角上最多的颜色
		int t[32] = { 0 };
		for (int k = 0; k < n; ++k)
		{
			int index = pose[k][face];
			int c = color[k][index];
			++t[c];
		}
		int max_cnt = t[0];
		for (int i = 1; i < 32; i++)
			if (t[i] > max_cnt)
				max_cnt = t[i];

		//累加改变量
		change_cnt += (n - max_cnt);
	}

	return change_cnt;
}
