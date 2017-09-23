//In-place
class Solution 
{
public:
    void reverseWords(string &s) 
    {
        if(s.length()<=1)
            return;
        
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int l=0, r=0;
        while(r<n)
        {
            while(r<n && s[r]!=' ')
                ++r;
            
            reverse(s.begin()+l, s.begin()+r);
            ++r;
            l=r;
        }
    }
};