class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        string ans(num1.size()+num2.size(),'0');
        int carry=0,curVal=0;
        
        for(int i=num1.size()-1;i>=0;i--)
        {
            carry=0;
            for(int j=num2.size()-1;j>=0;j--)
            {
                curVal=(ans[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                ans[i+j+1]=curVal%10+'0';
                carry=curVal/10;
            }
            ans[i]+=carry;
        }
        
        size_t startPos=ans.find_first_not_of("0");
        
        return startPos==string::npos ? "0" : ans.substr(startPos);
        
    }
};