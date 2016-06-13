class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        dfs("",n,0,ans);
        return ans;
    }
    
    void dfs(string cur,int left,int right,vector<string> &ans)
    {
        if(left==0 && right==0)
        {
            ans.push_back(cur);
            return;
        }
        
        if(left>0)
            dfs(cur+'(',left-1,right+1,ans);//多路dfs，同时work
        if(right>0)
            dfs(cur+')',left,right-1,ans);
    }
};