#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool mycmp(const string &a, const string &b);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n && n)
	{
		vector<string> s(n);

		for (int i = 0; i < n; i++)
			cin >> s[i];

		sort(s.begin(), s.end(), mycmp);

		for (int i = 0; i < n; i++)
			cout << s[i];
		cout << endl;
	}

	return 0;
}

bool mycmp(const string &a, const string &b)
{
	int min_len = min(a.length(), b.length());
	int max_len = max(a.length(), b.length());

	int cur = 0;
	while (cur < min_len)
	{
		if (a[cur] > b[cur])
			return true;
		else if (a[cur] < b[cur])
			return false;

		++cur;
	}

	if (cur == max_len)
		return true;
	else
	{
		if (a.length() < b.length())
			return mycmp(a, b.substr(min_len, max_len - min_len));
		else
			return mycmp(a.substr(min_len, max_len - min_len), b);
	}
}
