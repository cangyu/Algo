class Solution
{

public:

    int removeDuplicates(vector<int>& nums)
    {

        if(nums.size()<2)

            return nums.size();

        

        size_t cnt=0;

        

        for(size_t i=1;i<nums.size();i++)

            if(nums[i]!=nums[cnt])

                nums[++cnt]=nums[i];

        

        return cnt+1;

    }

};

//或者从反面考虑
class Solution

{

public:

    int removeDuplicates(vector<int>& nums) 

    {

        size_t repCnt=0;

        for(size_t i=1;i<nums.size();i++)

            if(nums[i-1]==nums[i])

                ++repCnt;

            else

                nums[i-repCnt]=nums[i];

        return nums.size()-repCnt;

    }

};



