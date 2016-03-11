//������Ȼ���ҵ���������ĽǶȣ�˼·��������Ҫ��
//������ѧ���ɷ�֤������̬�滮
//f(k)Ϊ����������1-k����Ҫ�����ټ�������
//�����Ѿ��ź����ˣ�ÿ��ֻ�迼����Ԫ�������һ����������Ĺ�ϵ�������ཻ������µģ����ཻ��������һ����������
//�㷨���ü��ϱ�ʾ����󷵻ؼ�����Ԫ�صĸ�������

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
				newgap.left = src[i].left;//ǰ������������֤����߽��ѡȡ���ᳬ����һ��ԭʼ�߽����߽磬���Ҳ���ᳬ����һ���������߽�
				newgap.right = min(src[i].right, last.right);
				res[res.size() - 1] = newgap;
			}
		}
	}
}
