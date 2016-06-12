class Solution
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        vector<string> m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string cur="";
        dfs(digits,0,cur,ans,m);
        return ans;
    }
    
    void dfs(const string &digits,size_t pos,string &cur,vector<string> &ans,const vector<string> &m)
    {
        if(pos>=digits.length())
        {
            if(digits.length()!=0)//Corner case:input string is empty,and in this case no need to output
                ans.push_back(cur);
            return;
        }
        
        size_t curDigit=digits[pos]-'0';
        
        for(size_t i=0;i<m[curDigit].length();i++)
        {
            cur.push_back(m[curDigit][i]);
            dfs(digits,pos+1,cur,ans,m);
            cur.pop_back();
        }
    }
};
