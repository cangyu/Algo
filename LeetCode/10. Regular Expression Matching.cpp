class Solution {
public:
	bool isMatch(string s, string p)
	{
		//return check(s, p, 0, 0);
		//return check_dp(s, p);
		return check_dp_modified(s, p);
	}

	bool check(string &s, string &p, int i, int j)//递归方法，关键是处理'*'
	{
		if (i > s.length() || j > p.length())
			return false;
		if (j == p.length())
			return i == s.length();

		if (p[j + 1] != '*')
		{
			if (i!=s.length() && (s[i] == p[j] || p[j] == '.'))
				return check(s, p, i + 1, j + 1);
			else
				return false;
		}
		else
		{
			while (i != s.length() && (s[i] == p[j] || p[j] == '.'))//不能直接i++，因为在*号后面还是有可能有同样的字符，在while里面的check体现了任意长度的‘*’
			{
				if (check(s, p, i, j + 2))
					return true;
				else
					i++;
			}
			return check(s, p, i, j + 2);
		}
	}

	bool check_dp(const string &s, const string &p)//dp方法，逐步划分匹配的条件
	{
		const int n = s.length(), m = p.length();
		vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));

		f[0][0] = true;
		for (int j = 2; j <= m; j++)
			f[0][j] = p[j - 1] == '*' && f[0][j - 2];

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (p[j - 1] != '*')
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				else
					f[i][j] = f[i][j - 2] || (f[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));//认为第一个不可能是'*'
			}
		}
		return f[n][m];
	}

	bool check_dp_modified(const string &s, const string &p)//去掉了不必要的空间开销
	{
		const int n = s.length(), m = p.length();
		vector<bool> f(m + 1, false);

		f[0] = true;
		for (int i = 2; i <= m; i++)
			f[i] = f[i - 2] && p[i - 1] == '*';

		for (int i = 1; i <= n; i++)
		{
			bool left_up = f[0];
			f[0] = false;
			for (int j = 1; j <= m; j++)
			{
				bool up = f[j];
				if (p[j - 1] != '*')
					f[j] = left_up && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				else
					f[j] = f[j - 2] || (up && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
				left_up = up;
			}
		}
		return f[m];
	}
};

