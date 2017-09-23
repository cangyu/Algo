class Solution
{
public:
    int findComplement(int num)
    {
        int t = (int)log2(num);
        t = (1<<(t+1))-1;
        return t-num;
    }
};
