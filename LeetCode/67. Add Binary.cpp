class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        int minLen=min(a.size(),b.size());
        string res;
        bool carry=false;
        reverse(a.begin(),a.end());reverse(b.begin(),b.end());
        for(int i=0;i<minLen;++i)
        {
            if(carry)
            {
                int t=(a[i]-'0')+(b[i]-'0')+1;
                res+=(t%2+'0');
                carry= (t/2==1);
            }
            else
            {
                res+=((a[i]-'0')^(b[i]-'0')+'0');
                carry= ((a[i]-'0')+(b[i]-'0')==2);
            }
        }
        string t = a.size()>b.size() ? a : b;
        int i=minLen;
        while(carry)
        {
            if(t[i]-'1'==0)
            {
                res+='0';
                carry=true;
                i++;
                if(i>=max(a.size(),b.size()))
                {
                    res+='1';
                    break;
                }    
            }
            else
            {
                res+=(1+'0');
                carry=false;
                ++i;
            }
        }
        //++i;
        if(i<=t.size()-1)
            res.append(t.substr(i));
        reverse(res.begin(),res.end());
        return res;
    }
};