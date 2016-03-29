class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)//corner case 1
            return false;
        if(x<10)//corner case 2,若x==0，则在下面的算长度的while循环会出错，虽然不影响结果
            return true;
        int cnt=0,t1=x,t2=x;
        while(t1)
        {
            cnt++;
            t1/=10;
        }
        while(t2 && cnt>1)//注意终止条件
        {
            int low=t2%10;
            int high=t2/pow(10,cnt-1);
            if(low!=high)
                return false;
            t2-=high*pow(10,cnt-1);
            t2/=10;
            cnt-=2;
        }
        return true;
    }
};