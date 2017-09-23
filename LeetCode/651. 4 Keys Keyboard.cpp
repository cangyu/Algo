//在逐次dp的过程中包含了连续的翻倍
//dp[k] = max{k, dp[k-1]+1, dp[k-2]+2, dp[k-3]*2, dp[k-4]*3, ... , dp[1]*(k-2)}
class Solution
{
public:
    int maxA(int N)
    {
        if(N<=6)
            return N;
        
        vector<int> dp= vector<int>(N+1);
        for(int i=0;i<N+1;i++)
            dp[i] = i;
        
        for(int i=7;i<=N;i++)
        {
            dp[i] = max(dp[i], dp[i-1]+1);
            dp[i] = max(dp[i], dp[i-2]+2);
            
            for(int j=2;j<=i-2;j++)
                dp[i] = max(dp[i], dp[i-j-1]*j);
        }
        
        return dp[N];
    }
};
