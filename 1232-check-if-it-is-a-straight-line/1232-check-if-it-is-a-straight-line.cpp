class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        int dy = a[1][1] - a[0][1];
        int dx = a[1][0] - a[0][0];
        int y0 = a[0][1];
        int x0 = a[0][0];

        for (int i = 2; i < a.size(); i++)
        {
            int y = a[i][1];
            int x = a[i][0];

            if (dx*(y - y0) != dy * (x - x0))
            {
                return false;
            }
        }
        return true;
    }
};