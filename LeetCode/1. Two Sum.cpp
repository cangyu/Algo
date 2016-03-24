//通过map来寻找counterpart，时间换空间
//由于题目中已经确保只有1个答案，所以可简化
//注意对称，不能先找到全部的counterpart再find，有可能target=2*nums[i]
//有可能是有正有负，不好剪枝

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int t=target-nums[i];
            if(m.find(t)!=m.end())
            {
                res[0]=i;
                res[1]=m[t];
                break;
            }
            else
                m[nums[i]]=i;
        }
        return res;
    }
};