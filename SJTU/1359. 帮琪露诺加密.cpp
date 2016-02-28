#include<iostream>
#include<string>

using namespace std;

//getline有两个，一个是在<string>中，不是string类的成员函数，有多个重载，在c++11中增加了对右值引用(&&)的重载
//另一个是istream类的成员函数，如教科书上所述，三个参数

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
