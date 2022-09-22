class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int curr = 0, sum = 0;
        for (int i = 2; i < nums.size(); ++i)
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) sum += ++curr;
            else curr = 0;
        return sum;
    }
};