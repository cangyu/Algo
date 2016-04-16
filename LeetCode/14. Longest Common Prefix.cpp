class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty())
            return "";
        if(strs[0]=="")
            return "";
            
        int minLen=strs[0].size();
        for(int i=1;i<strs.size();++i)
            minLen=strs[i].size()<minLen ? strs[i].size() : minLen;
        
        string res;
        for(int j=0;j<minLen;++j)
        {
            char t=strs[0][j];
            for(int i=1;i<strs.size();++i)
            {
                if(strs[i][j]!=t)
                    return res;
            }
            res+=t;
        }
        return res;
    }
};