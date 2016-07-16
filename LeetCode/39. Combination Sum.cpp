class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidate, int target)
    {
        vector<vector<int>> ans;
        vector<int> curAns;
        
        sort(candidate.begin(),candidate.end());//排序，然后根据次序在dfs中避免重复

        dfs(target,candidate,0,ans,curAns);//简洁写法！
        
        return ans;
    }
private:
    void dfs(int target,const vector<int> &candidate,int start, vector<vector<int>> &ans,vector<int> &curAns)
    {
        if(target==0)
            ans.push_back(curAns);
        
        int i=start;
        while(i<candidate.size() && target>=candidate[i])//下一步的dfs从当前序号开始，避免和前面已经走过的产生交叉从而重复
        {
            curAns.push_back(candidate[i]);
            dfs(target-candidate[i],candidate,i,ans,curAns);
            curAns.pop_back();
            ++i;
        }
    }
};