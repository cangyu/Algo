//ջ��Ӧ�ã����ʱ��Ҫ���˻��п����������������ʣ����

#include<iostream>
#include<cstring>

using namespace std;

bool isMatched(char *str, int n);

int main(int argc, char **argv)
{
	char brackets[101];
	int n;
	cin >> n;
	while (n--)
	{
		cin >> brackets;
		if (isMatched(brackets, strlen(brackets)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	//system("pause");
}

bool isMatched(char *str, int n)
{
	int stack_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			stack_cnt++;
		else
		{
			stack_cnt--;
			if (stack_cnt < 0)
				return false;
		}
	}
	if (stack_cnt != 0)//�����������ʣ����
		return false;
	else
		return true;
}
