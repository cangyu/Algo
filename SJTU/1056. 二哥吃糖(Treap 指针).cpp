//scanf大法好......！！！！scanf大法好......！！！！scanf大法好......！！！！
//用连续渐变的方法来记录糖果归属的变化，好！！！！！！！！！
//逻辑判断条件要小心，新方法中的b[p]==0与原来的p==0不一样！！！
//用treap来记录带有重复元素的值的集合，注意虽然旋转后待删除的节点与其父节点不满足堆序，但不论怎样旋转，其它节点之间的堆序总是得到满足的，所以在最后删掉后并不影响
//有重复元素的treap的insert与remove中关于size的处理，通过size来实现在log复杂度内找到第K大或第K小
//进一步认识BST的本质属性！不必拘泥于有无重复元素等等，可根据需要来重新设计，本质是中序遍历有序！
//理清算法思路：insert中插入路径上的所有节点都要加上插入的数量，先累加size再递归,
//remove的总体思路是先在子树上删完节点后再更新根的size信息，其中一些条件的判断可以简化:
//只有在删了子树上的点或重数大于1的根后才需要update size，删掉一个没有两个儿子的节点后不需要update size，直接return，
//所以在update size的时候也就不需要先去检测节点是否存在了，整个流程已经将这种情况排除在外了，
//注意直接删除时有个corner case是root，思维要缜密，如果要直接删掉的节点是root，检查一下发现直接删除后再返回并不会造成error，故直删之~

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
		int value;//节点的值
		int	cnt;//重数
		int fix;//引入的随机数，用来保证查找树的平衡
		int size;//以该节点为根的树的大小
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
				if (!t->left || !t->right) //没有两个子节点，可以直接删除,root也ok
				{
					pTreapNodeTypeDef old = t;
					t = t->left ? t->left : t->right;
					delete old;
					return;
				}
				else//有两个子节点，通过旋转，使得target node变成可直接删除的节点
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
