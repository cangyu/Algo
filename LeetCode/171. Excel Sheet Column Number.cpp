class Solution
{
public:
    int titleToNumber(string s)
    {
        int num=0, n=s.length();
        for(int i=0;i<n;++i)
            num+=(s[i]-'A'+1)*(pow(26,n-i-1));
        return num;
    }
};
