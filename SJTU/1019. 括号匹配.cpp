//栈的应用，检测时不要忘了还有可能是最后还有左括号剩下来

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
	if (stack_cnt != 0)//最后还有左括号剩下来
		return false;
	else
		return true;
}
