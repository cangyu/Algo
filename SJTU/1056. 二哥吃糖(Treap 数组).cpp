//scanf�󷨺�......��������scanf�󷨺�......��������scanf�󷨺�......��������
//����������ķ�������¼�ǹ������ı仯���ã�����������������
//�߼��ж�����ҪС�ģ��·����е�b[p]==0��ԭ����p==0��һ��������
//��treap����¼�����ظ�Ԫ�ص�ֵ�ļ��ϣ�ע����Ȼ��ת���ɾ���Ľڵ����丸�ڵ㲻������򣬵�����������ת�������ڵ�֮��Ķ������ǵõ�����ģ����������ɾ���󲢲�Ӱ��
//���ظ�Ԫ�ص�treap��insert��remove�й���size�Ĵ���ͨ��size��ʵ����log���Ӷ����ҵ���K����KС
//��һ����ʶBST�ı������ԣ����ؾ����������ظ�Ԫ�صȵȣ��ɸ�����Ҫ��������ƣ������������������
//�����㷨˼·��insert�в���·���ϵ����нڵ㶼Ҫ���ϲ�������������ۼ�size�ٵݹ�,
//remove������˼·������������ɾ��ڵ���ٸ��¸���size��Ϣ��ע�����ţ�update size��仰��Ҫ�Ŵ�λ�ã�������������һЩ�������жϿ��Լ�:
//ֻ����ɾ�������ϵĵ����������1�ĸ������Ҫupdate size��ɾ��һ��û���������ӵĽڵ����Ҫupdate size��ֱ��return��
//������update size��ʱ��Ҳ�Ͳ���Ҫ��ȥ���ڵ��Ƿ�����ˣ����������Ѿ�����������ų������ˣ�
//ע��ֱ��ɾ��ʱ�и�corner case��root��˼άҪ���ܣ����Ҫֱ��ɾ���Ľڵ���root�����һ�·���ֱ��ɾ�����ٷ��ز��������error����ֱɾ֮~

#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

const int max_num = 500005;

class Treap
{
private:
	struct treapNode
	{
		int left, right;
		int value;//�ڵ��ֵ
		int	cnt;//����
		int fix;//������������������֤��������ƽ��
		int size;//�Ըýڵ�Ϊ�������Ĵ�С
		treapNode(int val = 0, int c = 1) :left(0), right(0), value(val), cnt(c), fix(0), size(c) {}
	};

	treapNode p[max_num];
	int tail, root;

	void left_rotate(int &a)
	{
		int b = p[a].right;
		p[a].right = p[b].left;
		p[b].left = a;
		p[b].size = p[a].size;
		p[a].size = p[a].cnt + p[p[a].left].size + p[p[a].right].size;
		a = b;
	}

	void right_rotate(int &a)
	{
		int b = p[a].left;
		p[a].left = p[b].right;
		p[b].right = a;
		p[b].size = p[a].size;
		p[a].size = p[a].cnt + p[p[a].left].size + p[p[a].right].size;
		a = b;
	}

	void insert(int &r, int x, int c)
	{
		if (r == 0)
		{
			r = tail++;
			p[r].cnt = c;
			p[r].fix = rand();
			p[r].size = c;
			p[r].value = x;
		}
		else
		{
			p[r].size += c;

			if (x < p[r].value)
			{
				insert(p[r].left, x, c);
				if (p[p[r].left].fix < p[r].fix)
					right_rotate(r);
			}
			else if (x > p[r].value)
			{
				insert(p[r].right, x, c);
				if (p[p[r].right].fix < p[r].fix)
					left_rotate(r);
			}
			else
				p[r].cnt += c;
		}
	}

	void remove(int &r, int x)
	{
		if (r == 0)
			return;

		if (x < p[r].value)
			remove(p[r].left, x);
		else if (x>p[r].value)
			remove(p[r].right, x);
		else
		{
			if (p[r].cnt > 1)
				p[r].cnt--;
			else
			{
				if (p[r].left == 0 || p[r].right == 0)
				{
					r = p[r].left != 0 ? p[r].left : p[r].right;
					return;
				}
				else
				{
					if (p[p[r].left].fix < p[p[r].right].fix)
					{
						right_rotate(r);
						remove(p[r].right, x);
					}
					else
					{
						left_rotate(r);
						remove(p[r].left, x);
					}
				}
			}
		}
		p[r].size = p[r].cnt + p[p[r].left].size + p[p[r].right].size;//ע�����ŵ�λ�ã�����
	}

	int findKthMax(int r, int k)
	{
		if (r == 0 || k > p[r].size)
			return 0;

		int min_bound = 1 + p[p[r].right].size;
		int max_bound = p[r].cnt + min_bound - 1;

		if (k < min_bound)
			return findKthMax(p[r].right, k);
		else if (k>max_bound)
			return findKthMax(p[r].left, k - max_bound);
		else
			return p[r].value;
	}

public:
	Treap() :tail(1), root(0) { p[0].cnt = p[0].size = 0; }
	~Treap() {}

	void insert(int x) { insert(root, x, 1); }
	void insert(int x, int c) { insert(root, x, c); }
	void remove(int x) { remove(root, x); }
	int findKthMax(int k) { return findKthMax(root, k); }
};

int c[500005], b[500005];

inline int find(int x)
{
	return c[x] == x ? x : c[x] = find(c[x]);
}

void merge(int x, int y, Treap &ranklist)
{
	int p1 = find(x), p2 = find(y);
	if (p1 == p2 || b[p1] == 0 || b[p2] == 0)
		return;

	ranklist.remove(b[p1]);
	ranklist.remove(b[p2]);
	ranklist.insert(b[p1] + b[p2]);

	b[p2] += b[p1];
	b[p1] = 0;
	c[p1] = p2;
}

void eatup(int x, Treap &ranklist)
{
	int p = find(x);
	if (p == 0)
		return;

	ranklist.remove(b[p]);
	b[p] = 0;
}

Treap ranklist;

int main(int argc, char **argv)
{

	//freopen("1056.in", "r", stdin);
	//freopen("1056.out", "w", stdout);

	srand((int)time(0));

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		c[i] = i;
		b[i] = 1;
	}

	ranklist.insert(1, n);

	char cmd;
	int x, y, p;

	for (int i = 0; i < m; i++)
	{
		cmd = getchar();
		while (cmd != 'C'&&cmd != 'Q'&&cmd != 'D')
			cmd = getchar();

		switch (cmd)
		{
		case 'C':
			scanf("%d%d", &x, &y);
			merge(x, y, ranklist);
			break;
		case 'D':
			scanf("%d", &x);
			eatup(x, ranklist);
			break;
		case 'Q':
			scanf("%d", &p);
			printf("%d\n", ranklist.findKthMax(p));
			break;
		default:
			break;
		}
	}

	//system("pause");
	return 0;
}
