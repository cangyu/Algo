class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int wordLen=words[0].length();
        int totalLen=wordLen*words.size();
        vector<int> pos,ans;
        
        unordered_map<string,int> dict;
        for(auto v : words)
        {
            if(dict.find(v)==dict.end())
                dict[v]=0;
            else
                dict[v]++;
        }
        
        for(int i=0;i+wordLen<=s.length();i++)
            if(dict.find(s.substr(i,wordLen))!=dict.end())
                pos.push_back(i);
        
        sort(pos.begin(),pos.end());
        
        for(auto start : pos)
        {
            if(start+totalLen>s.length())
                break;
            
            unordered_map<string,int> m(dict);
            
            bool ok=true;
            for(int k=0;k<words.size();k++)
            {
                string t=s.substr(start+k*wordLen,wordLen);
                if(m.find(t)==m.end() || m[t]<0)
                {
                    ok=false;
                    break;
                }
                else
                    m[t]--;
            }
            if(ok)
                ans.push_back(start);
        }
        
        return ans;
    }
};
