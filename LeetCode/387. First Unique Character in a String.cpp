//The most basic idea
//也可以将每个字符最先出现的位置记录下来，这样在第二遍check的时候就无需再遍历一遍原始string了，直接排序
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> t = vector<int>(26, 0);
        
        int n = s.length();
        for(int i=0;i<n;i++)
            ++t[s[i]-'a'];
        
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(t[s[i]-'a']==1)
            {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
