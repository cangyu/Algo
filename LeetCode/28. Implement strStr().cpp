class Solution 
{
public:
    int strStr(string haystack, string needle)//KMP字符串匹配，有点DP的感觉 
    {
        if(needle.empty())
            return 0;
        
        vector<int> next=calcNext(needle);
        int ph=0,pn=0;
        
        for(ph=0;ph<haystack.length();ph++)
        {
            while(pn>0 && needle[pn]!=haystack[ph])
                pn=next[pn-1];
            if(needle[pn]==haystack[ph])
                pn++;
            if(pn==needle.length())
                return ph-pn+1;
        }
        return -1;
    }
    
private:
    vector<int> calcNext(const string &needle)
    {
        vector<int> next(needle.length(),0);
        for(int i=1;i<needle.length();i++)
        {
            int k=next[i-1];
            while(k>0 && needle[k]!=needle[i])
                k=next[k-1];
            if(needle[k]==needle[i])
                k++;
            next[i]=k;
        }
        return next;
    }
};