class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> ans;
        if(s.length()==0 || words.empty())
            return ans;
            
        unordered_map<string,int> dict;
        for(auto w : words)
            dict[w]++;
            
        const int wordLen=words[0].length();
        for(int i=0;i<wordLen;i++)
        {
            int left=i,validCnt=0;
            unordered_map<string,int> cur_dict;
            for(int j=i;j+wordLen<=s.length();j+=wordLen)
            {
                string curWord=s.substr(j,wordLen);
                if(dict.find(curWord)==dict.end())
                {
                    cur_dict.clear();
                    validCnt=0;
                    left=j+wordLen;
                }
                else
                {
                    cur_dict[curWord]++;
                    if(cur_dict[curWord]<=dict[curWord])
                        validCnt++;
                    else
                    {
                        while(cur_dict[curWord]>dict[curWord])
                        {
                            string headWord=s.substr(left,wordLen);
                            if(cur_dict[headWord]<=dict[headWord])
                                validCnt--;
                            cur_dict[headWord]--;
                            left+=wordLen;
                        }
                    }
                    
                    if(validCnt==words.size())
                    {
                        ans.push_back(left);
                        cur_dict[s.substr(left,wordLen)]--;
                        validCnt--;
                        left+=wordLen;
                    }
                }
            }
        }
        
        return ans;
    }
};
