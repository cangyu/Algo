#include<iostream>
#include<string>

using namespace std;

//getline��������һ������<string>�У�����string��ĳ�Ա�������ж�����أ���c++11�������˶���ֵ����(&&)������
//��һ����istream��ĳ�Ա��������̿�������������������

int main(int argc, char **argv)
{
	string s;
	getline(cin, s);

	int ans = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
			ans += (s[i] - 'a' + 27)*(i + 1);
		else if ('A' <= s[i] && s[i] <= 'Z')
			ans += (s[i] - 'A' + 1)*(i + 1);
		else
			continue;
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}
