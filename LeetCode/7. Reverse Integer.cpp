class Solution
{
public:
	int reverse(int x)
	{
		bool isNegative = x<0;
		long long t = x, res = 0;//由于int的取值范围是-2147483648~2147483647，两端的极值不相等，所以要用long long
		if (isNegative)
			t = -t;
		while (t)
		{
			res *= 10;
			res += t % 10;
			t /= 10;
		}
		long long up_bound = (long long)1 << 31;//单独拿出来，便于下面判断语句的书写
		if ((isNegative && res>up_bound) || (!isNegative && res>up_bound - 1))
			return 0;
		else
			return (int)(isNegative ? -res : res);
	}
};