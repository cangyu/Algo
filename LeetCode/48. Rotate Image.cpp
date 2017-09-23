class Solution 
{
public:
    void swap(int &a,int &b)
    {
        a^=b;
        b^=a;
        a^=b;
    }
    void rotate(vector<vector<int>>& matrix)//先对角线转一次，在沿垂直轴转一次，其它也可
    {
        const int n=matrix.size();
        
        for(int i=1;i<=n-1;++i)
            for(int j=0;j<=i-1;++j)
                swap(matrix[j][i],matrix[i][j]);
        for(int i=0;i<=n/2-1;++i)
            for(int j=0;j<=n-1;++j)
                swap(matrix[j][i],matrix[j][n-1-i]);
    }
};