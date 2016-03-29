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

		long long ans = 0, up_bound = (long long)1 << 31;//�˴�Ҫ�Ƚ�1ת��Ϊlong long������������Ĭ��Ϊ32λ��
		while (i<str.length() && '0' <= str[i] && str[i] <= '9')
		{
			ans *= 10;
			ans += str[i++] - '0';
			if ((isNegative && ans>up_bound) || (!isNegative && ans>up_bound - 1))//64λ���������Ҳֻ�ܱ�ʾ��20λ��Ҫ��ֹ��������
				return isNegative ? INT_MIN : INT_MAX;
		}
		return (int)(isNegative ? -ans : ans);//�����Զ������������corner case��strΪ�ջ�ȫ�ǿ��ַ�����Թ��м�Ĵ���
	}
};