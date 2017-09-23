class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        const int n=nums.size();
        int p= n&1 ? ((n+1)&2)>>1 :(n|(n&2)>>1);
        for(auto t : nums)
            p^=t;
        return p;
    }
};