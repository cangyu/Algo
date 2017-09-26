#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Job
{
public:
    int s, d;
    Job():s(0), d(0) {}
    
    bool operator<(const Job &rhs) const
    {
        if(d==rhs.d)
            return s<rhs.s;
        else
            return d<rhs.d;
    }
};

int solve(vector<Job> &g)
{
    int n = g.size();
    sort(g.begin(), g.end());
    
    int xb1=-1, xb2=-1, sum = 0, max1=0, max2=0;
    for(int i=0;i<n;i++)
    {
        sum+=g[i].s;
        int tmp = max(sum-g[i].d, 0);
        
        if(tmp>max1)
        {
            max2 = max1;
            max1 = tmp;
            xb1 = xb2;
            xb2 = i;
        }
        else if(tmp>max2)
        {
            max2 = tmp;
            xb1 = xb2;
            xb2 = i;
        }
        else
            continue;
    }
    
    int ret = max1 + max2;
    if(xb1==-1 || xb2==-1)
        return ret;
    
    for(int i=0;i<=xb1;i++)
    {
        sum = max1 = max2 = 0;
        for(int j=0;j<n;j++)
        {
            if(j==i)
                continue;
            
            sum+=g[j].s;
            int tmp = max(sum-g[j].d, 0);
            
            if(tmp>max1)
            {
                max2 = max1;
                max1 = tmp;
            }
            else if(tmp>max2)
                max2 = tmp;
            
            if(j==xb2)
            {
                sum += g[i].s;
                int tmp = max(sum -g[i].d, 0);
                if(tmp>max1)
                {
                    max2 = max1;
                    max1 = tmp;
                }
                else if(tmp>max2)
                    max2 = tmp;
            }
        }
        ret = min(ret, max1 + max2);
    }
    
    return ret;
}

int main(int argc, char **argv)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<Job> job_list(n);
        for(int i=0;i<n;i++)
            cin>>job_list[i].s>>job_list[i].d;

        int ans = solve(job_list);
        cout<<ans<<endl;
    }
    return 0;
}
