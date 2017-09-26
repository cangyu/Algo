//Recursive
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return _find_kth(nums, 0, nums.size()-1, k);
    }
    
    int _find_kth(vector<int> &num, int p, int r, int k)
    {
        int q = partition(num, p, r);
        int cnt = q-p;
        if(cnt==k-1)
            return num[q];
        else if(cnt<k-1)
            return _find_kth(num, q, r, k-cnt);
        else
            return _find_kth(num, p, q-1, k);
    }
    
    int partition(vector<int> &num, int p, int r)
    {
        int x = num[r];
        int i = p-1;
        for(int j=p;j<r;j++)
        {
            if(num[j]>=x)
            {
                ++i;
                swap(num[i], num[j]);
            }
        }
        
        ++i;
        swap(num[i], num[r]);
        return i;
    }
};

//Iterative
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int left = 0, right = nums.size()-1;
        for(;;)
        {
            int cut = partition(nums, left, right);
            int cnt = cut - left;
            if(cnt==k-1)
                return nums[cut];
            else if(cnt<k-1)
            {
                left = cut;
                k-=cnt;
            }
            else
                right = cut-1;
        }
    }
    
    int partition(vector<int> &num, int p, int r)
    {
        int x = num[r];
        int i = p-1;
        for(int j=p;j<r;j++)
        {
            if(num[j]>=x)
            {
                ++i;
                swap(num[i], num[j]);
            }
        }
        
        ++i;
        swap(num[i], num[r]);
        return i;
    }
};