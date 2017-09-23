//最初始想法，逐个扫描，然后标记，扫完其它的再将标记改回来
class Solution
{
public:
    int countBattleships(vector<vector<char>>& board)
    {
        int ni = board.size();
        int nj = board[0].size();
        
        int ans = 0;
        for(int i=0;i<ni;i++)
        {   for(int j=0;j<nj;j++)
            if(board[i][j]=='X')
            {
                ans+=1;
                
                //mark
                int dir=0, lb=0, rb=0;
                if((i+1<ni && board[i+1][j]=='X') || (i-1>=0 && board[i-1][j]=='X'))
                {
                    dir=1;
                    int ti = i-1;
                    while(ti>=0 && board[ti][j]=='X')
                    {
                        board[ti][j]='.';
                        ti-=1;
                    }
                    lb = ti+1;
                    ti = i+1;
                    while(ti<ni && board[ti][j] == 'X')
                    {
                        board[ti][j] = '.';
                        ti+=1;
                    }
                    rb = ti-1;
                }
                if((j+1<nj && board[i][j+1]=='X') || (j-1>=0 && board[i][j-1]=='X'))
                {
                    dir=2;
                    int tj = j-1;
                    while(tj>=0 && board[i][tj]=='X')
                    {
                        board[i][tj]='.';
                        tj-=1;
                    }
                    lb = tj+1;
                    tj = j+1;
                    while(tj<nj && board[i][tj]=='X')
                    {
                        board[i][tj] = '.';
                        tj+=1;
                    }
                    rb = tj-1;
                }
                
                board[i][j] = '.';
                ans += countBattleships(board);
                
                //mark back
                if(dir==0)
                    board[i][j]='X';
                if(dir==1)
                {
                    for(int ti=lb;ti<=rb;ti++)
                        board[ti][j]='X';
                }
                if(dir==2)
                {
                    for(int tj=lb;tj<=rb;tj++)
                        board[i][tj]='X';
                }
                
                return ans;
            }
        }
        return ans;
    }
};

//With inspection, better
class Solution
{
public:
    int countBattleships(vector<vector<char>>& board)
    {
        int ni = board.size();
        int nj = board[0].size();
        
        int ans = 0;
        for(int i=0;i<ni;i++)
            for(int j=0;j<nj;j++)
                if(board[i][j]=='X')
                {
                    bool ok1 = i==0 || board[i-1][j]!='X';
                    bool ok2 = j==0 || board[i][j-1]!='X';
                    if(ok1 && ok2)
                        ++ans;
                }
        
        return ans;
    }
};
