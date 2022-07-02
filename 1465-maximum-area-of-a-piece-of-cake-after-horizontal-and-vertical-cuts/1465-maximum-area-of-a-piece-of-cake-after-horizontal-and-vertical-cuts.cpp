class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hcurr = h, vcurr = w,
            h_max_diff = 0, v_max_diff = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end(), greater<int>());
        sort(verticalCuts.begin(), verticalCuts.end(), greater<int>());
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        
        for (auto &i : horizontalCuts) {
            h_max_diff = max(h_max_diff, hcurr - i);
            hcurr = i;
        }
        for (auto &i : verticalCuts) {
            v_max_diff = max(v_max_diff, vcurr - i);
            vcurr = i;
        }
        
        long long int hz = (long long int) h_max_diff;
        long long int vz = (long long int) v_max_diff;
        return (int) ((hz * vz) % 1000000007);
    }
};