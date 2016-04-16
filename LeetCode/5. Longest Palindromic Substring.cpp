class Solution
{
public:
    string longestPalindrome(string s) //从中间向两边找
    {
        if(s.length()<2)
            return s;
            
        int start=0,longest=1;
        int i=0;
        while(i<s.length())
        {
            if(s.length()-i<=longest/2)
                break;
            int a=i,b=i;
            while(b<s.length()-1 && s[b+1]==s[b]) 
                b++;
            i=b+1;
            while(a>0 && b<s.length()-1 && s[a-1]==s[b+1])
            {   
                a--;
                b++;
            }
            if(b-a+1>longest)
            {
                longest=b-a+1;
                start=a;
            }
        }
        return s.substr(start,longest);
    }
};