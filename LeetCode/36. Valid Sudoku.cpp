class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //虽然分3遍依次检测每行，每列，每个box的话能节省点空间，但还可以进一步用空间换时间
        
        vector<bitset<9>> row(9,bitset<9>(0x000)),col(9,bitset<9>(0x000)),box(9,bitset<9>(0x000));
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0'-1;
                    int k=3*(i/3)+j/3;
                    if(row[i].test(num) || col[j].test(num) || box[k].test(num))
                        return false;

                    row[i].set(num);//bitset是从右向左数的！！！
                    col[j].set(num);
                    box[k].set(num);
                }
            }
        }
        return true;
    }
};
