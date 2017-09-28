//统计s1中字符出现的次数，然后s2上做sliding window
class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        vector<int> pattern(26, 0);
        for(int i=0;i<s1.length();i++)
            ++pattern[s1[i]-'a'];
        
        int tl = s2.length()-s1.length();
        for(int left=0; left<=tl; ++left)
        {
            int c = s2[left]-'a';
            if(pattern[c]!=0)
            {
                int right=-1;
                bool ok = true;
                for(int k=0;k<s1.length();++k)
                {
                    right=left+k;
                    int c = s2[right]-'a';
                    if(pattern[c]<=0)
                    {
                        ok = false;
                        break;
                    }
                    else
                        --pattern[c];
                }
                if(ok)
                    return true;
                else
                {
                    for(int t=left;t<right;++t)
                        ++pattern[s2[t]-'a'];
                }
            }
        }
        return false;
    }
};