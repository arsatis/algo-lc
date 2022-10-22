class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool isMonotonic(vector<int>& nums) {
        bool inc = false, dec = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                if (dec) return false;
                inc = true;
            }
            if (nums[i] < nums[i - 1]) {
                if (inc) return false;
                dec = true;
            }
        }
        return true;
    }
};