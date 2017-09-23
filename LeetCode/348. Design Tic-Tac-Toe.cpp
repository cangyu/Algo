//空间换时间，记录每行每列和对角线上的累积情况
class TicTacToe
{
public:
    /** Initialize your data structure here. */
    vector<vector<int>> row_cnt, col_cnt, diag_cnt;
    int dim;
    TicTacToe(int n):dim(n)
    {
        row_cnt = vector<vector<int>>(n, vector<int>(2, 0));
        col_cnt = vector<vector<int>>(n, vector<int>(2, 0));
        diag_cnt = vector<vector<int>>(2, vector<int>(2, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
     @param row The row of the board.
     @param col The column of the board.
     @param player The player, can be either 1 or 2.
     @return The current winning condition, can be either:
     0: No one wins.
     1: Player 1 wins.
     2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        int p = player-1;
        row_cnt[row][p]+=1;
        col_cnt[col][p]+=1;
        if(row==col)
            diag_cnt[0][p]+=1;
        if(row+col==dim-1)
            diag_cnt[1][p]+=1;
        
        if(row_cnt[row][p]==dim ||col_cnt[col][p]==dim || diag_cnt[0][p]==dim || diag_cnt[1][p]==dim)
            return player;
        else
            return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
