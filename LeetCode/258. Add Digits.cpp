//Trivial solution
class Solution
{
public:
    int addDigits(int num)
    {
        if(num<10)
            return num;
        
        int t=0;
        while(num)
        {
            t+=num%10;
            num/=10;
        }
        return addDigits(t);
    }
};

//With observation
class Solution
{
public:
    int addDigits(int num)
    {
        if(num==0)
            return 0;
        int ret=num%9;
        return ret==0 ? 9 : ret;
    }
};
