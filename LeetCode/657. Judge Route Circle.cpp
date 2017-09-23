class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int u=0, d=0, l=0, r=0;
        for(int i=0;i<moves.length();i++)
        {
            switch(moves[i])
            {
                case 'U':
                    ++u;
                    break;
                case 'D':
                    ++d;
                    break;
                case 'R':
                    ++r;
                    break;
                case 'L':
                    ++l;
                    break;
                default:
                    break;
            }
        }
        
        return u==d && l==r;
    }
};
