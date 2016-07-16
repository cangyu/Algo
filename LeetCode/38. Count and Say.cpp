class Solution
{
public:
    string countAndSay(int n) 
    {
        string ans="1";
        for(int i=2;i<=n;i++)
            solve_next(ans);
        return ans;
    }
private:
    void solve_next(string &cur)
    {
        string ans;
        int i=0,j=0,cnt=0;
        while(i<cur.length())
        {
            cnt=1;
            j=i;
            while(j+1<cur.length() && cur[j+1]==cur[j])
            {
                cnt++;
                j++;
            }
            ans.push_back('0'+cnt);
            ans.push_back(cur[i]);
            i=j+1;
        }
        cur=ans;
    }
};