/*
ID: yhcy1991
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct fraction
{
	int x, y;
	fraction *left, *right;
	int fix;
	fraction(int a, int b, fraction *l=NULL, fraction *r=NULL) :x(a), y(b), left(l), right(r), fix(rand()){ reduce(); }
	void reduce()
	{
		if (x == 0)
			y = 1;
		else
		{
			for (int i = 2; i <= x; i++)
			{
				while (x%i == 0 && y%i == 0)
					x /= i, y /= i;
			}
		}
	}
	void print(ofstream &fout)
	{
		fout << x << '/' << y << endl;
	}
	friend inline bool operator<(const fraction &f1, const fraction &f2);
	friend inline bool operator>(const fraction &f1, const fraction &f2);
	friend inline bool operator==(const fraction &f1, const fraction &f2);
};

inline bool operator<(const fraction &f1, const fraction &f2)
{
	return (f1.x)*(f2.y) < (f2.x)*(f1.y);
}
inline bool operator>(const fraction &f1, const fraction &f2)
{
	return (f1.x)*(f2.y) > (f2.x)*(f1.y);
}
inline bool operator==(const fraction &f1, const fraction &f2)
{
	return (f1.x)*(f2.y) == (f2.x)*(f1.y);
}

class treap
{
private:
	fraction *root;

	void right_rotate(fraction* &rt)
	{
		fraction *rtl = rt->left;
		rt->left = rtl->right;
		rtl->right = rt;
		rt = rtl;
	}

	void left_rotate(fraction* &rt)
	{
		fraction *rtr = rt->right;
		rt->right = rtr->left;
		rtr->left = rt;
		rt = rtr;
	}

	void insert(fraction* &r, fraction frac)
	{
		if (!r)
			r = new fraction(frac);
		else if (frac < *r)
		{
			insert(r->left, frac);
			if (r->left->fix>r->fix)
				right_rotate(r);
		}
		else if (frac > *r)
		{
			insert(r->right, frac);
			if (r->right->fix > r->fix)
				left_rotate(r);
		}
		else
			return;
	}
	void makeEmpty(fraction *r)
	{
		if (!r)
			return;
		makeEmpty(r->left);
		makeEmpty(r->right);
		delete r;
		r = NULL;
	}

	void print(fraction *r, ofstream &fout)
	{
		if (!r)
			return;
		print(r->left, fout);
		r->print(fout);
		print(r->right, fout);
	}

public:
	treap() :root(NULL) {}
	~treap() { makeEmpty(root); }
	void insert(fraction frac) { insert(root, frac); }
	void print(ofstream & fout) { print(root, fout); }
};

int main()
{
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	srand((int)time(0));

	int n;
	treap ft;

	fin >> n;
	ft.insert(fraction(0, 1));
	ft.insert(fraction(1, 1));

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			fraction t(j, i);
			if (t.y == i)
				ft.insert(t);
		}
	}

	ft.print(fout);

	fin.close();
	fout.close();
	return 0;
}
