//scanf大法好......！！！！scanf大法好......！！！！scanf大法好......！！！！
//用连续渐变的方法来记录糖果归属的变化，好！！！！！！！！！
//逻辑判断条件要小心，新方法中的b[p]==0与原来的p==0不一样！！！
//用treap来记录带有重复元素的值的集合，注意虽然旋转后待删除的节点与其父节点不满足堆序，但不论怎样旋转，其它节点之间的堆序总是得到满足的，所以在最后删掉后并不影响
//有重复元素的treap的insert与remove中关于size的处理，通过size来实现在log复杂度内找到第K大或第K小
//进一步认识BST的本质属性！不必拘泥于有无重复元素等等，可根据需要来重新设计，本质是中序遍历有序！
//理清算法思路：insert中插入路径上的所有节点都要加上插入的数量，先累加size再递归,
//remove的总体思路是先在子树上删完节点后再更新根的size信息（注意括号，update size这句话不要放错位置！！！），其中一些条件的判断可以简化:
//只有在删了子树上的点或重数大于1的根后才需要update size，删掉一个没有两个儿子的节点后不需要update size，直接return，
//所以在update size的时候也就不需要先去检测节点是否存在了，整个流程已经将这种情况排除在外了，
//注意直接删除时有个corner case是root，思维要缜密，如果要直接删掉的节点是root，检查一下发现直接删除后再返回并不会造成error，故直删之~

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
		int value;//节点的值
		int	cnt;//重数
		int fix;//引入的随机数，用来保证查找树的平衡
		int size;//以该节点为根的树的大小
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
		p[r].size = p[r].cnt + p[p[r].left].size + p[p[r].right].size;//注意括号的位置！！！
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
