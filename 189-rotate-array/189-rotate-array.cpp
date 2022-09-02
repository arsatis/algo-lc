class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        std::rotate(nums.rbegin(), nums.rbegin() + k % nums.size(), nums.rend());
    }
};