class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        vector<int> c(s.length(),0);
        int ans=0;
        
        for(int i=s.length()-2;i>=0;i--)
        {
            if(s[i]=='(')
            {
                int post=i+c[i+1]+1;
                if(post<s.length() && s[post]==')')
                {
                    c[i]=2+c[i+1];
                    if(post+1<s.length())
                        c[i]+=c[post+1];
                }
                ans=max(ans,c[i]);
            }
        }
        return ans;
    }
};
