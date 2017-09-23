class Solution
{
public:
    int numDecodings(string s)
    {
        if(s.length()==0)
            return 0;
        
        int n = s.length();
        vector<int> dp = vector<int>(n+1, 0);
        dp[0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            int cp = i-1;
            if(s[cp]>='1' && s[cp]<='9')
                dp[i]+=dp[i-1];
            
            if(cp-1>=0)
            {
                int t = stoi(s.substr(cp-1, 2));
                if(t<=26 && t>=10)
                    dp[i]+=dp[i-2];
            }
        }
        
        return dp[n];
    }
};
