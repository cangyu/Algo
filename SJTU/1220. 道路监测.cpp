//先排序，然后找到划分问题的角度！思路清晰很重要！
//可用数学归纳法证明，动态规划
//f(k)为排序后的区间1-k所需要的最少监测点数，
//由于已经排好序了，每次只需考虑新元素与最后一个监测点区间的关系，若不相交则添加新的，若相交则更新最后一个监测点区间
//算法中用集合表示，最后返回集合中元素的个数即可

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct gap
{
	int left;
	int right;
}GapTypeDef, *pGapTypeDef;

bool my_gapSort_func(GapTypeDef g1, GapTypeDef g2);
void process(const vector<GapTypeDef> &src, vector<GapTypeDef> &res);

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	int a, b;
	vector<GapTypeDef> gaps(n, { 0, 0 });
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		gaps[i].left = a - b;
		gaps[i].right = a + b;
	}

	sort(gaps.begin(), gaps.end(), my_gapSort_func);

	vector<GapTypeDef> detect_gap;

	process(gaps, detect_gap);

	cout << detect_gap.size() << endl;

	//system("pause");
	return 0;
}

bool my_gapSort_func(GapTypeDef g1, GapTypeDef g2)
{
	return (g1.left < g2.left);
}

void process(const vector<GapTypeDef> &src, vector<GapTypeDef> &res)
{
	for (unsigned int i = 0; i < src.size(); i++)
	{
		if (res.empty())
			res.push_back(src[i]);
		else
		{
			GapTypeDef last = res[res.size() - 1];
			if (src[i].left > last.right)
				res.push_back(src[i]);
			else
			{
				GapTypeDef newgap;
				newgap.left = src[i].left;//前面的排序操作保证了左边界的选取不会超过上一个原始边界的左边界，因而也不会超过上一个结果的左边界
				newgap.right = min(src[i].right, last.right);
				res[res.size() - 1] = newgap;
			}
		}
	}
}
