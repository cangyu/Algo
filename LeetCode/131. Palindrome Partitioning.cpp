class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ret;
        vector<string> tmp;
        
        dfs(s, 0, tmp, ret);
        
        return ret;
    }
    
    void dfs(const string &s, int begin, vector<string> &tmp, vector<vector<string>> &ret)
    {
        if(begin==s.length())
        {
            ret.push_back(tmp);
            return;
        }
        
        int left = begin;
        for(int right=begin;right<s.length();++right)
        {
            if(check(s, left, right))
            {
                tmp.push_back(s.substr(left, right-left+1));
                dfs(s, right+1, tmp, ret);
                tmp.pop_back();
            }
        }
    }
    
    bool check(const string &s, int l, int r)
    {
        while(l<r)
        {
            if(s[l]==s[r])
            {
                ++l;
                --r;
            }
            else
                return false;
        }
        return true;
    }
};