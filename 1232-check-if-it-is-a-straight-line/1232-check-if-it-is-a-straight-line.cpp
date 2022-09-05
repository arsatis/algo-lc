class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pair<double, double> diff = {
            coordinates[0][0] - coordinates[1][0],
            coordinates[0][1] - coordinates[1][1]
        };
        
        for (int i = 2; i < coordinates.size(); ++i) {
            if (!diff.first) {
                if (coordinates[0][0] != coordinates[i][0]) return false;
            } else {
                double m = (double) (coordinates[i][0] - coordinates[0][0]) / diff.first;
                if (coordinates[0][1] + m * diff.second < coordinates[i][1] - 0.1 ||
                    coordinates[0][1] + m * diff.second > coordinates[i][1] + 0.1)
                    return false;
            }
        }
        return true;
    }
};