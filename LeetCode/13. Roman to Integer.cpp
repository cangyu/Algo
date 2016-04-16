class Solution
{
public:
    int romanToInt(string s)//Ҳ������map��˼·�����жϵ�ǰ�������ȡ������ȡ��
    {
        int res=0;
        const int len=s.size();
        char c;
        for(int i=len-1;i>=0;--i)
        {
            c=s[i];
            switch(c)
            {
                case 'I':
                    res+=(res>=5 ? -1 : 1);
                    break;
                case 'V':
                    res+=5;
                    break;
                case 'X':
                    res+=10*(res>=50 ? -1 : 1);
                    break;
                case 'L':
                    res+=50;
                    break;
                case 'C':
                    res+= 100*(res>=500 ? -1 : 1);
                    break;
                case 'D':
                    res+=500;
                    break;
                case 'M':
                    res+=1000*(res>=5000 ? -1:1);
                    break;
            }
        }
        return res;
    }
};