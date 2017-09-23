//利用最后一个被置零的行来存储列置零信息
class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(),n=matrix[0].size();
        if(m<1 || n<1)
            return;
        
        int last_zero_row=-1;
        for(int i=m-1;i>=0;--i)
        {
            for(int j=0;j<=n-1;++j)
                if(matrix[i][j]==0)
                {
                    last_zero_row=i;
                    break;
                }
            if(last_zero_row!=-1)
                break;
        }
        if(last_zero_row==-1)
            return;
        
        for(int i=0;i<last_zero_row;++i)
        {
            bool curRowToZero=false;
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==0)
                {
                    curRowToZero=true;
                    matrix[last_zero_row][j]=0;
                }
            }
            if(curRowToZero)
                for(int j=0;j<n;++j)
                    matrix[i][j]=0;
        }
        
        for(int j=0;j<n;++j)
        {
            if(matrix[last_zero_row][j]==0)
                for(int i=0;i<m;++i)
                    matrix[i][j]=0;
        }
        
        for(int j=0;j<n;++j)
            if(matrix[last_zero_row][j]!=0)
                matrix[last_zero_row][j]=0;
        
        
    }
};