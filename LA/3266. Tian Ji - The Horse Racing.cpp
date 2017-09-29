#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000+5;

int tianji[N];
int qiwang[N];
int n;

int solve()
{
    int tb=0, te = n-1, qb=0, qe=n-1;
    int ans = 0;
    for(int k=0;k<n;k++)
    {
        if(tianji[te]<qiwang[qe])//田忌当前最快干不过齐王当前最快，用最慢的当替死鬼
        {
            ++tb;
            --qe;
            --ans;
        }
        else if(tianji[te]>qiwang[qe])//田忌当前最快干得过齐王当前最快，直接怼
        {
            --te;
            --qe;
            ++ans;
        }
        else//田忌当前最快==齐王当前最快，根据最慢的情况适当保存实力
        {
            if(tianji[tb]>qiwang[qb])
            {
                ++tb;
                ++qb;
                ++ans;
            }
            else
            {
                if(tianji[tb]<qiwang[qe])
                    --ans;
                ++tb;
                --qe;
            }
        }
    }
    return ans;
}

int main(int argc, char **argv)
{
    while(scanf("%d", &n) && n)
    {
        for(int i=0;i<n;i++)
            scanf("%d", tianji+i);
        for(int i=0;i<n;i++)
            scanf("%d", qiwang+i);
        
        sort(tianji, tianji+n);
        sort(qiwang, qiwang+n);
        
        int win = solve()*200;
        printf("%d\n", win);
    }
    return 0;
}
