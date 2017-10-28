class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans = 0;
        if(grid.size()==0)
            return ans;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1')
                {
                    ++ans;
                    dfs(i, j, grid);
                }
        
        return ans;
    }
    
    int di[4]={0, 0, 1, -1};
    int dj[4]={1, -1, 0, 0};
    
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1')
            return;
        
        grid[i][j]='0';
        
        for(int k=0;k<4;k++)
            dfs(i+di[k], j+dj[k], grid);
    }
};