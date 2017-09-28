class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
            return 0;
        const int m=grid.size();
        const int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(dfsDetector(i,j,m,n,grid))
                  ++cnt;  
            }
        }
        return cnt;
    }
private:
    bool dfsDetector(int i,int j,const int &m,const int &n,vector<vector<char>> &grid)
    {
        const static vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        const int dirCnt=dir.size();
        if(i<0 || i>=m || j<0 || j>=n)
            return false;
        if(grid[i][j]=='1')
        {
            grid[i][j]='2';
            for(int k=0;k<dirCnt;++k)
                dfsDetector(i+dir[k][0],j+dir[k][1],m,n,grid);
            return true;
        }
        else
            return false;
    }
};