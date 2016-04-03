//scanf�󷨺�......��������scanf�󷨺�......��������scanf�󷨺�......��������
//����������ķ�������¼�ǹ������ı仯���ã�����������������
//�߼��ж�����ҪС�ģ��·����е�b[p]==0��ԭ����p==0��һ��������
//��treap����¼�����ظ�Ԫ�ص�ֵ�ļ��ϣ�ע����Ȼ��ת���ɾ���Ľڵ����丸�ڵ㲻������򣬵�����������ת�������ڵ�֮��Ķ������ǵõ�����ģ����������ɾ���󲢲�Ӱ��
//���ظ�Ԫ�ص�treap��insert��remove�й���size�Ĵ���ͨ��size��ʵ����log���Ӷ����ҵ���K����KС
//��һ����ʶBST�ı������ԣ����ؾ����������ظ�Ԫ�صȵȣ��ɸ�����Ҫ��������ƣ������������������
//�����㷨˼·��insert�в���·���ϵ����нڵ㶼Ҫ���ϲ�������������ۼ�size�ٵݹ�,
//remove������˼·������������ɾ��ڵ���ٸ��¸���size��Ϣ������һЩ�������жϿ��Լ�:
//ֻ����ɾ�������ϵĵ����������1�ĸ������Ҫupdate size��ɾ��һ��û���������ӵĽڵ����Ҫupdate size��ֱ��return��
//������update size��ʱ��Ҳ�Ͳ���Ҫ��ȥ���ڵ��Ƿ�����ˣ����������Ѿ�����������ų������ˣ�
//ע��ֱ��ɾ��ʱ�и�corner case��root��˼άҪ���ܣ����Ҫֱ��ɾ���Ľڵ���root�����һ�·���ֱ��ɾ�����ٷ��ز��������error����ֱɾ֮~

#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

#define nullptr NULL

class Treap
{
private:
	typedef struct treapNode
	{
		treapNode *left, *right;
		int value;//�ڵ��ֵ
		int	cnt;//����
		int fix;//������������������֤��������ƽ��
		int size;//�Ըýڵ�Ϊ�������Ĵ�С
		treapNode(int v = 0, int c = 1) :left(nullptr), right(nullptr), value(v), cnt(c), fix(rand()), size(c) {}
		inline int lsize() { return left ? left->size : 0; }
		inline int rsize() { return right ? right->size : 0; }
	}TreapNodeTypeDef, *pTreapNodeTypeDef;

	pTreapNodeTypeDef root;

	void left_rotate(pTreapNodeTypeDef &t)
	{
		pTreapNodeTypeDef tr = t->right;
		t->right = tr->left;
		tr->left = t;
		tr->size = t->size;
		t->size = t->cnt + t->lsize() + t->rsize();
		t = tr;
	}

	void right_rotate(pTreapNodeTypeDef &t)
	{
		pTreapNodeTypeDef tl = t->left;
		t->left = tl->right;
		tl->right = t;
		tl->size = t->size;
		t->size = t->cnt + t->lsize() + t->rsize();
		t = tl;
	}

	void insert(pTreapNodeTypeDef &t, int val, int c)
	{
		if (!t)
			t = new treapNode(val, c);
		else
		{
			t->size += c;
			if (val < t->value)
			{
				insert(t->left, val, c);
				if (t->left->fix < t->fix)
					right_rotate(t);
			}
			else if (val > t->value)
			{
				insert(t->right, val, c);
				if (t->right->fix < t->fix)
					left_rotate(t);
			}
			else
				t->cnt += c;
		}
	}

	void remove(pTreapNodeTypeDef &t, int val)
	{
		if (!t)
			return;

		if (val < t->value)
			remove(t->left, val);
		else if (val>t->value)
			remove(t->right, val);
		else
		{
			if (t->cnt > 1)
				t->cnt--;
			else
			{
				if (!t->left || !t->right) //û�������ӽڵ㣬����ֱ��ɾ��,rootҲok
				{
					pTreapNodeTypeDef old = t;
					t = t->left ? t->left : t->right;
					delete old;
					return;
				}
				else//�������ӽڵ㣬ͨ����ת��ʹ��target node��ɿ�ֱ��ɾ���Ľڵ�
				{
					if (t->left->fix < t->right->fix)
					{
						right_rotate(t);
						remove(t->right, val);
					}
					else
					{
						left_rotate(t);
						remove(t->left, val);
					}
				}
			}
		}
		t->size = t->cnt + t->lsize() + t->rsize();//update size
	}

	int findKthMax(pTreapNodeTypeDef t, int k)
	{
		if (!t || k > t->size)
			return 0;

		int min_bound = 1 + t->rsize();
		int max_bound = t->cnt + t->rsize();

		if (k < min_bound)
			return findKthMax(t->right, k);
		else if (k > max_bound)
			return findKthMax(t->left, k - max_bound);
		else
			return t->value;
	}

	void makeEmpty(pTreapNodeTypeDef &t)
	{
		if (t == nullptr)
			return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
		t = nullptr;
	}

public:

	Treap() :root(nullptr) {}
	~Treap() { makeEmpty(root); }

	void insert(int val) { insert(root, val, 1); }
	void insert(int val, int c) { insert(root, val, c); }
	void remove(int val) { remove(root, val); }
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


int main(int argc, char **argv)
{
	srand((int)time(0));

	Treap ranklist;

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
