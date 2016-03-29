class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)//corner case
            return s;
        //若s为空串也可正常跳过
        vector<string> str(numRows);
        bool low2high=true;
        int n=s.length(),t=numRows-1;
        int cur=0;
        int remain=n%t;
        while(n>remain)
        {
            if(low2high)
            {
                for(int i=0;i<t;i++)
                    str[i].push_back(s[cur++]);
            }
            else
            {
                for(int i=0;i<t;i++)
                    str[numRows-1-i].push_back(s[cur++]);
            }
            n-=t;
            low2high=!low2high;
        }
        if(low2high)
        {
            for(int i=0;i<remain;i++)
                str[i].push_back(s[cur++]);
        }
        else
        {
            for(int i=0;i<remain;i++)
                str[numRows-1-i].push_back(s[cur++]);
        }
        string res;
        for(int i=0;i<numRows;i++)
            res.append(str[i]);
        return res;
    }
};