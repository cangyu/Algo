class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) //用Hash加速
    {
        unordered_map<string, int> dict;
        int idx = 0;
        vector<vector<string>> ret;
        
        for(int i=0;i<strs.size();i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(dict.find(tmp)==dict.end())   
            {
                dict[tmp]=idx++;
                ret.push_back({strs[i]});
            }
            else
                ret[dict[tmp]].push_back(strs[i]);
        }
        
        return ret;
    }
};