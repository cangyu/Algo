//清晰明了的思路比所谓的效率更重要，一定要能保证正确性
//算乘法的时候对原始串是从最后往前扫的

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

string LargeNumDivision(string &dividend, string &divisor);
unsigned int str_divide_simple(string &dividend, string &divisor);
string str_multiply_simple(string &src, int multiple);
string str_subtract_simple(string minuend, string subtrahend);
int myStrCmp(const string &str1, const string &str2);

int main(int argc, char **argv)
{
	string a, b;
	cin >> a >> b;

	string ans = LargeNumDivision(a, b);
	cout << ans << endl;
	//system("pause");
	return 0;
}

string LargeNumDivision(string &dividend, string &divisor)
{
	unsigned int curIndexOfDividend = 0, curAns = 0;
	string residue, ans;

	while (curIndexOfDividend < dividend.length())
	{
		residue += dividend[curIndexOfDividend];
		curAns = str_divide_simple(residue, divisor);
		ans += (curAns + '0');
		curIndexOfDividend++;
	}

	unsigned int k = 0;
	while (k<ans.length() && ans[k] == '0')
		k++;

	return ans.substr(k, ans.length() - k);
}

unsigned int str_divide_simple(string &dividend, string &divisor)
{
	for (int i = 9; i >= 0; i--)
	{
		string cur = str_multiply_simple(divisor, i);
		if (myStrCmp(cur, dividend) > 0)
		{
			//do nothing
		}
		else if (myStrCmp(cur, dividend) < 0)
		{
			dividend = str_subtract_simple(dividend, cur);
			return i;
		}
		else
		{
			dividend = "";
			return i;
		}
	}
}

string str_multiply_simple(string &src, int multiple)
{
	if (multiple <= 0 || multiple >= 10)
		return "";
	else if (multiple == 1)
		return src;
	else
	{
		int carry = 0, digit = 0, tmpRes = 0;
		string ans;
		for (int i = src.length() - 1; i >= 0; i--)
		{
			digit = src[i] - '0';
			tmpRes = digit*multiple + carry;
			ans += ('0' + tmpRes % 10);
			carry = tmpRes / 10;
		}
		if (carry != 0)
			ans += ('0' + carry);

		reverse(ans.begin(), ans.end());
		return ans;
	}
}

string str_subtract_simple(string minuend, string subtrahend)
{
	int borrow = 0, digit = 0;
	string ans;
	int i = minuend.length() - 1, j = subtrahend.length() - 1;
	while (i >= 0 && j >= 0)
	{
		digit = minuend[i] - subtrahend[j] - borrow;
		if (digit < 0)
		{
			digit += 10;
			borrow = 1;
		}
		else
			borrow = 0;

		ans += (digit + '0');

		i--, j--;
	}
	while (i >= 0)
	{
		digit = minuend[i] - '0' - borrow;
		if (digit < 0)
		{
			digit += 10;
			borrow = 1;
		}
		else
			borrow = 0;

		ans += (digit + '0');

		i--;
	}

	reverse(ans.begin(), ans.end());

	unsigned int k = 0;
	while (k<ans.length() && ans[k] == '0')
		k++;

	return ans.substr(k, ans.length() - k);
}

int myStrCmp(const string &str1, const string &str2)
{
	if (str1.length() < str2.length())
		return -1;
	else if (str1.length() > str2.length())
		return 1;
	else
		return strcmp(str1.c_str(), str2.c_str());
}
