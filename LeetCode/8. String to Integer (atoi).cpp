class Solution
{
public:
	int myAtoi(string str)
	{
		int i = 0;
		while (str[i] == ' ')
			i++;
		bool isNegative = false;
		if (str[i] == '-' || str[i] == '+')
			isNegative = (str[i++] == '-');

		long long ans = 0, up_bound = (long long)1 << 31;//此处要先将1转换为long long，否则计算机会默认为32位的
		while (i<str.length() && '0' <= str[i] && str[i] <= '9')
		{
			ans *= 10;
			ans += str[i++] - '0';
			if ((isNegative && ans>up_bound) || (!isNegative && ans>up_bound - 1))//64位的整型最多也只能表示到20位，要防止奇葩输入
				return isNegative ? INT_MIN : INT_MAX;
		}
		return (int)(isNegative ? -ans : ans);//这里自动处理了输入的corner case，str为空或全是空字符则会略过中间的代码
	}
};