class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin() + (n / 2), nums.end());
        int median = nums[n / 2];
        for (int i = 0; i < n; ++i) steps += abs(nums[i] - median);
        return steps;
    }
};