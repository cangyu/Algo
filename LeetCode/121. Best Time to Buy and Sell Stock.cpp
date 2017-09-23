class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int max_profit=0;
        int cur_profit=0;
        
        for(int i=1;i<prices.size();i++)
        {
            int tmp = prices[i]-prices[i-1];
            if(cur_profit<0)
                cur_profit = tmp;
            else
                cur_profit += tmp;
            
            max_profit = max(max_profit, cur_profit);
        }
        
        return max_profit;
    }
};