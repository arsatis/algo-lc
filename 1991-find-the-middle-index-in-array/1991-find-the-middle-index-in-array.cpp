class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int findMiddleIndex(vector<int>& nums) {
        int prefixSum = 0, sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (prefixSum == sum - prefixSum - nums[i]) return i;
            prefixSum += nums[i];
        }
        return -1;
    }
};