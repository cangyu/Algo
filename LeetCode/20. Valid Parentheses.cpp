class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        if(s.empty())
            return false;
            
        for(auto c: s)
        {
            if(c=='(' || c=='[' || c=='{')
                st.push(c);
            else
            {
                switch(c)
                {
                case ')':
                    if(st.empty() || st.top()!='(')//可检测的前提是要非空！
                        return false;
                    else
                        st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top()!='[')
                        return false;
                    else
                        st.pop();
                    break;
                case '}':
                    if(st.empty() || st.top()!='{')
                        return false;
                    else
                        st.pop();
                    break;
                default:
                    return false;
                }
            }
        }
        return st.empty();
    }
};