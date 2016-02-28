//从后往前合并，最后再反转过来，思路类似归并
//注意进位

#include<iostream>
#include<cstring>

using namespace std;

const int MAX_LEN = 100005;

void reverse(char *str, int left, int right);
void swap(char *str, int n1, int n2);

int main(int argc, char **argv)
{
	char a[MAX_LEN], b[MAX_LEN], r[MAX_LEN];
	cin >> a >> b;
	int a_len = strlen(a);
	int b_len = strlen(b);
	int i = a_len - 1, j = b_len - 1, k = 0, carry = 0;

	while (i >= 0 && j >= 0)
	{
		int t = a[i--] - '0' + b[j--] - '0' + carry;
		r[k++] = '0' + t % 10;
		if (t >= 10)
			carry = 1;
		else
			carry = 0;
	}

	while (i >= 0)
	{
		int t = a[i--] - '0' + carry;
		r[k++] = '0' + t % 10;
		if (t >= 10)
			carry = 1;
		else
			carry = 0;
	}

	while (j >= 0)
	{
		int t = b[j--] - '0' + carry;
		r[k++] = '0' + t % 10;
		if (t >= 10)
			carry = 1;
		else
			carry = 0;
	}

	if (carry == 1)
		r[k++] = '0' + 1;

	r[k] = 0;
	reverse(r, 0, k);

	cout << r;

	//system("pause");
}

void reverse(char *str, int left, int right)
{
	int i = left, j = right - 1;

	while (i < j)
		swap(str, i++, j--);
}

void swap(char *str, int n1, int n2)
{
	char t = str[n1];
	str[n1] = str[n2];
	str[n2] = t;
}
