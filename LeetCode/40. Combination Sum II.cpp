class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidate, int target)
    {
        vector<vector<int>> ans;
        vector<int> curAns;
        
        sort(candidate.begin(),candidate.end());//����Ȼ����ݴ�����dfs�б����ظ�

        dfs(target,candidate,0,ans,curAns);//���д����
        
        return ans;
    }
private:
    void dfs(int target,const vector<int> &candidate,int start, vector<vector<int>> &ans,vector<int> &curAns)
    {
        if(target==0)
        {
            ans.push_back(curAns);
            return;
        }
		
        int i=start;
        while(i<candidate.size() && target>=candidate[i])//��һ����dfs�ӵ�ǰ��ſ�ʼ�������ǰ���Ѿ��߹��Ĳ�������Ӷ��ظ�
        {
            curAns.push_back(candidate[i]);
            dfs(target-candidate[i],candidate,i+1,ans,curAns);
            curAns.pop_back();
            
            do{i++;}while(i<candidate.size() && candidate[i]==candidate[i-1]);//�����i+1����������ظ�����Ҫ����Ԫ�������ظ�
        }
    }
};