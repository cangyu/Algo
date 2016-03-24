//ͨ��map��Ѱ��counterpart��ʱ�任�ռ�
//������Ŀ���Ѿ�ȷ��ֻ��1���𰸣����Կɼ�
//ע��Գƣ��������ҵ�ȫ����counterpart��find���п���target=2*nums[i]
//�п����������и������ü�֦

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