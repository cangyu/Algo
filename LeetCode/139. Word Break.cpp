class Solution 
{
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)//dp
    {
        vector<bool> f(s.size(),false);
        f[0] = wordDict.find(s.substr(0,1))!=wordDict.end();
        for(int i=1;i<s.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if((f[j]||wordDict.find(s.substr(0,j+1))!=wordDict.end()) && wordDict.find(s.substr(j+1,i-j))!=wordDict.end())
                {
                    f[i]=true;
                    break;
                }
            }
        }
        return f[s.size()-1] || wordDict.find(s)!=wordDict.end();
    }
};