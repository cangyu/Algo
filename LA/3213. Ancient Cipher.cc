#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int c1[26], c2[26];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	string s1, s2;
	while (cin >> s1 >> s2)
	{
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for (int i = 0; i < s1.length(); i++)
		{
			++c1[s1[i] - 'A'];
			++c2[s2[i] - 'A'];
		}

		sort(c1, c1 + 26);
		sort(c2, c2 + 26);

		bool ok = true;
		for (int i = 0; i < 26; i++)
			if (c1[i] != c2[i])
			{
				ok = false;
				break;
			}

		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}
