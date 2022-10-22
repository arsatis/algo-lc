class Solution {
public:
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