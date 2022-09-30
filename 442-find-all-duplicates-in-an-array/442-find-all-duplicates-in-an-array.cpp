class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        for (int i : nums) {
            int tmp = abs(i) - 1;
            if (nums[tmp] < 0) duplicates.emplace_back(tmp + 1);
            nums[tmp] *= -1;
        }
        return move(duplicates);
    }
};