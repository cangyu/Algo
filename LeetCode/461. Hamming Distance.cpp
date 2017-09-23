class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int t = x^y;
        int cnt =0;
        while(t)
        {
            t=t&(t-1);//Get the last '1' in binay representation
            ++cnt;
        }
        return cnt;
    }
};
