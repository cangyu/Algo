class Solution
{
public:
	int reverse(int x)
	{
		bool isNegative = x<0;
		long long t = x, res = 0;//����int��ȡֵ��Χ��-2147483648~2147483647�����˵ļ�ֵ����ȣ�����Ҫ��long long
		if (isNegative)
			t = -t;
		while (t)
		{
			res *= 10;
			res += t % 10;
			t /= 10;
		}
		long long up_bound = (long long)1 << 31;//�����ó��������������ж�������д
		if ((isNegative && res>up_bound) || (!isNegative && res>up_bound - 1))
			return 0;
		else
			return (int)(isNegative ? -res : res);
	}
};