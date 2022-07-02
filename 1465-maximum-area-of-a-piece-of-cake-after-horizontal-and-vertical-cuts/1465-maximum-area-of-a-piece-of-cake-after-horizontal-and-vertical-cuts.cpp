class Solution {
    int prod_mod(int &h_max, int &v_max) {
        long long int h = (long long int) h_max;
        long long int v = (long long int) v_max;
        return (int) ((h * v) % 1000000007);
    }
    
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
        
        return prod_mod(h_max_diff, v_max_diff);
    }
};