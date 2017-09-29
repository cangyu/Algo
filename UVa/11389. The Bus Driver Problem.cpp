#include<cstdio>
#include<algorithm>
#include<functional>

using namespace std;

const int N = 100 + 5;
int afternoon[N];
int night[N];
int n, d, r;

int main(int argc, char **argv)
{
    while(scanf("%d%d%d", &n, &d, &r))
    {
        if(!n && !d && !r)
            break;
        
        for(int i=0;i<n;i++)
            scanf("%d", afternoon+i);
        for(int i=0;i<n;i++)
            scanf("%d", night+i);
        
        sort(afternoon, afternoon+n);
        sort(night, night+n, greater<int>());
        
        int pay =0;
        for(int i=0;i<n;i++)
        {
            int cur = afternoon[i]+night[i];
            if(cur>d)
                pay +=cur-d;
        }
        pay*=r;
        printf("%d\n", pay);
    }
    return 0;
}
