class Solution 
{
public:
    int findMinArrowShots(vector<pair<int, int>>& points) 
    {
        sort(points.begin(), points.end(), gap_cmp);
        
        int arrow = INT_MIN;
        int cnt = 0;
        
        for(int i=0;i<points.size();i++)
        {
            if(arrow==INT_MIN || points[i].first>arrow)
            {
                arrow = points[i].second;
                ++cnt;
            }
        }
        
        return cnt;
    }
    
    static bool gap_cmp(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        if(lhs.second < rhs.second)
            return true;
        else if(lhs.second > rhs.second)
            return false;
        else
            return lhs.first<rhs.first;
    }
};