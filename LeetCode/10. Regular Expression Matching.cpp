class Solution {//�ݹ鷽�����ؼ��Ǵ���'*'
public:
    bool isMatch(string s, string p) {
      return check(s,p,0,0);  
    }

    bool check(string &s, string &p, int i, int j)
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
    		while (i!=s.length() && (s[i] == p[j] || p[j] == '.'))
        	{
    			if (check(s, p, i, j + 2))//����ֱ��i++����Ϊ��*�ź��滹���п�����ͬ�����ַ�����while�����check���������ⳤ�ȵġ�*��
    				return true;
    			else
    				i++;
    		}
    		return check(s, p, i, j + 2);
    	}
    }
};