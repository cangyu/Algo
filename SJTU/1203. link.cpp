//类内可以直接用对象中private的元素，如swap中直接使用rhs的length等
//一般有operator+也要有operator=,operator+一般重载为全局函数，以便进行自动类型转换，而operator=则必须重载为类的成员函数
//using copy-and-swap strategy to avoid copying self
//类内元素摆放的顺序很重要，因为构造时是按照元素声明的顺序来构造的，这里就要先构造length，然后才能在构造data中使用length，否则会挂掉
//注意管理内存，以及带模板的写法

#include <iostream>
#include <string>

using namespace std;

template < typename T >
class List
{
private:
	int length;
	int cur;
	T *data;

	void swap(List &rhs)
	{
		using std::swap;
		swap(length, rhs.length);
		swap(cur, rhs.cur);
		swap(data, rhs.data);
	}

public:

	List(int len) :length(len), cur(-1), data(new T[len]) {}

	List(const List &rhs) :length(rhs.length), cur(-1), data(new T[length])
	{
		for (int i = 0; i <length; i++)
			insert(rhs.get(i));
		cur = rhs.cur;
	}

	~List()
	{
		delete[] data;
		length = cur = -1;
	}
	
	int getLen() const { return length; }
	int getPos() const { return cur; }
	void insert(const T &val) { data[++cur] = val; }
	T& get(int index) { return data[index]; }
	T get(int index) const { return data[index]; }

	void printAll()
	{
		for (int i = 0; i <length; i++)
			cout << data[i] << ' ';
		cout << endl;
	}

	List& operator=(List rhs)
	{
		swap(rhs);
		return *this;
	}
};

template < typename T >
List<T> operator+ (const List<T> &lhs,const List<T> &rhs)
{
	int n1 = lhs.getLen();
	int n2 = rhs.getLen();
	int n = n1 + n2;
	List<T> r(n);

	for (int i = 0; i < n1; i++)
		r.insert(lhs.get(i));
	for (int i = 0; i < n2; i++)
		r.insert(rhs.get(i));

	return r;
}

template <typename T >
void resolve(int n, int m)
{
	List<T> s1(n), s2(m);
	T t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s1.insert(t);
	}
	for (int j = 0; j < m; j++)
	{
		cin >> t;
		s2.insert(t);
	}

	List <T> s(n + m);
	s = s1 + s2;
	s.printAll();
}

int main(int argc, char **argv)
{
	string type;
	int n, m;
	cin >> type >> n >> m;
	if (type == "int")
		resolve<int>(n, m);
	else if (type == "char")
		resolve <char >(n, m);
	else if (type == "double")
		resolve <double >(n, m);

	//system("pause");

	return 0;
}
