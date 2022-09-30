class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size(), peak = 1, valley = 1;
        for (int i=1; i<size; ++i){
            if (nums[i]>nums[i-1]) peak = valley + 1;
            else if (nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak, valley);
    }
};