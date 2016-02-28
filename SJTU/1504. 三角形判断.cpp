//取中间长度的方法，防止溢出

#include<iostream>

using namespace std;

inline int max(int a, int b)
{
	return (a > b ? a : b);
}

inline int min(int a, int b)
{
	return (a < b ? a : b);
}

int main(int argc, char **argv)
{
	int t[3];
	for (int i = 0; i < 3; i++)
		cin >> t[i];
	int a = min(min(t[0], t[1]), t[2]);
	int c = max(max(t[0], t[1]), t[2]);
	int b = 0;
	if (t[1] == a && t[2] == c || t[1] == c && t[2] == a)
		b = t[0];
	else if (t[0] == a && t[2] == c || t[0] == c && t[2] == a)
		b = t[1];
	else
		b = t[2];

	if (a > 0)
	{
		if (b>c - a)//防止溢出的写法
		{
			if (a*a == c*c - b*b)
				cout << "right-angled triangle";
			else
				cout << "triangle";
		}
		else
			cout << "not triangle";
	}
	else
		cout << "not triangle";

	//system("pause");
}
