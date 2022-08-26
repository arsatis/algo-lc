class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int m = nums.size() >> 1;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        int ans = 0, mid = nums[m];
        for (int& x: nums) ans += abs(x - mid);
        return ans;
    }
};